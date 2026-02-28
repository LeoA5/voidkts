voidkts is a web-service built on top of the oat++ framework, postgres, and flyway. It's designed to be portable, utilizing OCI containers, and private, as it's intended to only allow communication over a mesh VPN such as Tailscale.

The setup relies on some kind of container service with compose support, such as podman-compose or docker. The caddyfile is also explicitly designed to work with tailscale or localhost interfaces only, so that routing will need to change if something else is desired.

Several services use hidden folders or files that are not included in the repository, theres are ./.data/\*, ./.secrets/\*, and upstreams.caddy. Ensure these are configured appropriately.