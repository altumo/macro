
Overview
--------

Macro is many things. Primarily, it's an open source (MIT License), modern c++, object relational mapper (ORM).

However, it's also an application framework, with project generation that generates:

  - projects with scaffolding
  - models from existing relational schemas (postgres)
  - models from existing streaming schema (kafka)
  - schema versioning service
  - infrastructure generation

Basically, Macro aims to use a single source file to generate all things necessary for a modern web application.
It does this in a way that is especially considerator of how that application will change over time. Thus, it has primary
support for schema mutations, infrastructure mutations, data mutations in a way that provides first-class support
for zero-downtime, rolling upgrades, blue/green deployments, and automatic canary deployments.



Build
-----

```
brew install openssl
brew unlink openssl && brew link openssl --force
cmake .
make
./build/macro
```
