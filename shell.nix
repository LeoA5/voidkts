{ pkgs? import <nixpkgs> {} }:

pkgs.mkShell{
    packages = [ pkgs.python315 pkgs.libgcc pkgs.libmysqlclient pkgs.mariadb ];
}