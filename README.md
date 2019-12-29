
Overview
--------

Macro aims to see the big picture. 

At the highest level, Macro aims to use a single source file to generate all things necessary for a modern web application. It does this in a way that is especially considerate of how that application will change over time. Thus, it has primary support for schema mutations, infrastructure mutations, and data mutations, in a way that provides first-class support for zero-downtime, rolling upgrades, blue/green deployments, and automatic canary deployments. Macro strictly ensures that all mutations have both rollout and rollback logic, and only have [FULL_TRANSITIVE](https://docs.confluent.io/current/schema-registry/avro.html#summary) schema compatibility.

Macro is many things. Primarily, it's an open-source (MIT License), modern c++, object-relational mapper (ORM).

However, it's also an application framework, with project generation that generates:

  - Projects with scaffolding, Kubernetes integration, and CircleCI integration.
  - Models from existing relational schemas (Postgres - recommend CockroachDB by default).
  - Models from existing streaming schemas (Kafka - recommend Kafka by default).
  - Schema versioning service.
  - Infrastructure generation (AWS, Kubernetes, Istio, CoreOS operator for your application).
  - [OpenAPI 3.0.2](https://swagger.io/docs/specification/about/) Document.
  - c++ HTTP API Client, native iOS HTTP API client (Swift), native Android HTTP API client (Java/Kotlin).
  - Integration tests.
  - Unit tests.

Macro was heavily influenced by [PropelORM](http://propelorm.org), so it automatically builds Query objects for each model so that you can be very productive, creating extensible queries and use [Query Embedding](http://propelorm.org/documentation/04-relationships.html). 

Macro models are dual purpose: they can be used with relational databases, streaming databases, or both (the default). By default, all data mutations are committed to the source of truth (the highly-consistent relation database), then published to the streaming database with exactly-once semantics to implement [CDC](https://en.wikipedia.org/wiki/Change_data_capture), even if your relational database does not support [CDC](https://en.wikipedia.org/wiki/Change_data_capture) yet.

Macro aims to contain a rich set of examples because *examples are excellent documentation*. If you find that your usage of Macro is not well-represented by the existing examples, please open an issue, and we'll do our best to create an example that helps others easily learn your use case or apply your use case in their projects. Thanks, in advance, for taking the time to create an issue!



Build
-----

```
brew install openssl
brew unlink openssl && brew link openssl --force
cmake .
make
./build/macro
```
