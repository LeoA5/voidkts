voidkts is a web-service tool that utilizes OCI containers for portability, and communication over a tailscale network for privacy.

Later versions will include a full install script that will ensure tailscale is setup, logged in, and enabled, configure caddy's reverse proxying to use appropriate tailscale host and dns names, setup cron jobs for automatic updates and database secret rotations, and run flyway whenever git updates are detected to ensure database migration and versioning is kept consistent.
