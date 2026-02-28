
# VoidKTS
This is a framework designed for quickly deploying small-scale, portable,  and private web applications.
## Features
- Utilizes OCI containers according to standard specifications to remain compatible with tools like podman-compose, as well as docker. This provides platform agnostic containerization, which allows for easy and flexible setups with whatever tools you wish to use.
- Built from and with only free or open source tools. The backend utilizes PostgreSQL as a databse, Caddy serves custom html+css+js on the front end, and the custom C++ REST API is built on top of Oat++, which is lightweight zero-dependency web framework.
- Ntfy for push notifications when key services go offline.

## Limitations
- This framework was not designed to be open to the public internet, and security decisions were made under the assumption that it would only run on a local or private network, but not necessarily with trusted devices on those networks. This means tools for things like spam or bot-net monitoring, etc. are *not* included by default.
- This framework was designed for small-scale internal or personal applications, and not made with the intention of a high-degree of parallelism, or large concurrent user-base. Tools were put in place for CI/CD, SQL migration control, and other ways of ensuring consistent up-time, as well as supporting NTFY for mobile push notifications should any of the three core services go offline for any reason.

# Getting Started
An init script is included that generates needed local folders for container data-storage, secret keys, and can optionally set up cron jobs on a specified cadence for querying for updates, and managing their installs and container restarts when applicable, rotating passwords, and ensuring key containers remain online.

## Example VPN config:
As specified in the limitaions section, the intention of this framework is to build web apps that run locally, or run over a private network. An easy to configure, and free option, that works well enough at the time of writing, although headscale is a very good, and fully open source alternative if preferred. Assuming you've set up a simple tailscale client, and have magicdns enabled, an example Caddyfile would be something like:

    # magicdnsdomain is the domain pointing to your host machine's Tailscale network IP
    localhost, magicdnsdomain.ts.net {
    root * /srv
    file_server

    # Route traffic from /api/ through api container on port 9000 
    # (default REST api listening port)
    handle /api/* {
        uri strip_prefix /api
        reverse_proxy api:9000
      }
    }

