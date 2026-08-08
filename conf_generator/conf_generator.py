import argparse
import json
import os
import re
import string
import sys


def main(argv):
  parser = argparse.ArgumentParser(
      description='Tiny code generator',
      fromfile_prefix_chars='@')

  parser.add_argument('--json_file', required=True, help='The input file')
  parser.add_argument('--template', required=True, help='.h template to render')
  parser.add_argument('--out_file', required=True, help='.h file to write')
  parser.add_argument('--namespace', required=True, help='C++ namespace to emit into')
  options = parser.parse_args(argv[1:])

  config = load_config(options.json_file)
  gen_h(config, options.template, options.out_file, options.namespace)

  return 0


def load_config(path):
  with open(path, 'r') as inp:
    return json.load(inp)


def to_identifier(value):
  identifier = re.sub(r'[^0-9a-zA-Z]+', '_', value.strip())
  if not identifier or identifier[0].isdigit():
    identifier = '_' + identifier
  return identifier


def to_guard(output_path):
  return to_identifier(output_path.replace(os.sep, '_')).upper() + '_'


def render_checkpoints(values):
  enumerators = []
  for at, value in enumerate(v for v in values if v and v.strip()):
    enumerators.append('%s = %d,' % (to_identifier(value), at))
  return '\n    '.join(enumerators)


def gen_h(config, template_path, output_path, namespace):
  with open(template_path, 'r') as inp:
    template = string.Template(inp.read())

  contents = template.substitute(
      GUARD=to_guard(output_path),
      NAMESPACE=namespace,
      APPLICATION_NAME=json.dumps(config['name']),
      CHECKPOINTS=render_checkpoints(config['checkoints']),
  )

  with open(output_path, 'w') as out:
    out.write(contents)


if __name__ == '__main__':
  sys.exit(main(sys.argv))
