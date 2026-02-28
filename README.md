# VoidKTS
This is a framework designed for quickly deploying small-scale, portable,  and private web applications.
## Features
- Utilizes OCI containers according to standard specifications to remain compatible with tools like podman-compose, as well as docker. This provides platform agnostic containerization, which allows for easy and flexible setups with whatever tools you wish to use.
- Built from and with only free or open source tools. The backend utilizes PostgreSQL as a databse, Caddy serves custom html+css+js on the front end, and the custom C++ REST API is built on top of Oat++, which is lightweight zero-dependency web framework.

## Limitations
- This framework was not designed to be open to the public internet, and security decisions were made under the assumption that it would only run on a local or private network, but not necessarily with trusted devices on those networks. This means tools for things like spam or bot-net monitoring, etc. are *not* included by default.
- This framework was designed for small-scale internal or personal applications, and not made with the intention of a high-degree of parallelism, or large concurrent user-base. Tools were put in place for CI/CD, SQL migration control, and other ways of ensuring consistent up-time, as well as supporting NTFY for mobile push notifications should any of the three core services go offline for any reason.
