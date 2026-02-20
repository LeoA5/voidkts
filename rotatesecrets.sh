# write a new password, restart maria, and update the root user
set -e

# Needed to run the script docker commans
root_local_pw=$(cat ./.secrets/mariadb/rootpw.txt)
echo $root_local_pw

# Update % root
new_wild_root_pw=$(openssl rand -base64 24 | tee ./.secrets/mariadb/root%pw.txt)
echo $new_wild_root_pw
echo $root_local_pw
docker exec mariadb_main sh -c "
    mariadb --socket=/run/mysqld/mysqld.sock -u root -p\"$root_local_pw\" -e \"
        ALTER USER 'root'@'%' IDENTIFIED BY '$new_wild_root_pw';
    \"
"

# Update local root ALWAYS MAKE THIS THE LAST ONE UPDATED
new_local_root_pw=$(openssl rand -base64 24 | tee ./.secrets/mariadb/rootpw.txt)
echo $new_local_root_pw
echo $root_local_pw
docker exec mariadb_main sh -c "
    mariadb --socket=/run/mysqld/mysqld.sock -u root -p\"$root_local_pw\" -e \"
        ALTER USER 'root'@'localhost' IDENTIFIED BY '$new_local_root_pw';
    \"
"