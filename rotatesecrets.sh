set -e

# Update server user
new_host_pw=$(openssl rand -base64 24 | tee ./.secrets/postgresql/hostpw.txt)
docker exec postgresql \
    psql -U host -d postgres \
    -c "ALTER USER host WITH PASSWORD '$new_host_pw';"