# Rotate all user passwords in the MariaDB from the host machine
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