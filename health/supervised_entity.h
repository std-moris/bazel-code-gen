#pragma once

namespace health
{
class SupervisedEntity
{
  public:
    virtual ~SupervisedEntity()                              = default;
    SupervisedEntity()                                       = default;
    SupervisedEntity(const SupervisedEntity&)                = delete;
    SupervisedEntity(SupervisedEntity&&) noexcept            = delete;
    SupervisedEntity& operator=(const SupervisedEntity&)     = delete;
    SupervisedEntity& operator=(SupervisedEntity&&) noexcept = delete;
};
} // namespace health
