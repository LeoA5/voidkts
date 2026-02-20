# TODO: add init system if local data folders aren't present (should be trivial)

# Rotate all user passwords in the MariaDB from the host machine
# All secrets are 32 characters base64 to ensure no password length
# conflict with MariaDB/MySQL, so they get 3/4(32) = 24 bytes of input.
set -e

# Load current root@localhost password to use for operations
root_local_pw=$(cat ./.secrets/mariadb/rootpw.txt)

# Update root@%
new_wild_root_pw=$(openssl rand -base64 24 | tee ./.secrets/mariadb/root%pw.txt)
docker exec mariadb_main sh -c "
    mariadb --socket=/run/mysqld/mysqld.sock -u root -p\"$root_local_pw\" -e \"
        ALTER USER 'root'@'%' IDENTIFIED BY '$new_wild_root_pw';
    \"
"

# Update root@localhost ALWAYS MAKE THIS THE LAST ONE UPDATED
# SERIOUSLY, THIS PASSWORD IS USED TO AUTHENTICATE COMMANDS FROM THIS SHELL
# YOU HAVE TO UPDATE ROOT_LOCAL_PW IF YOU TRY TO DO ANYTHING AFTER THIS
new_local_root_pw=$(openssl rand -base64 24 | tee ./.secrets/mariadb/rootpw.txt)
docker exec mariadb_main sh -c "
    mariadb --socket=/run/mysqld/mysqld.sock -u root -p\"$root_local_pw\" -e \"
        ALTER USER 'root'@'localhost' IDENTIFIED BY '$new_local_root_pw';
    \"
"