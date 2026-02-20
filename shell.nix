{ pkgs? import <nixpkgs> {} }:

pkgs.mkShell{
    packages = [
        pkgs.python315 
        pkgs.gcc
        pkgs.libgcc 
        pkgs.libmysqlclient 
        pkgs.oatpp
        pkgs.mariadb
        pkgs.pkg-config
    ];

    # The path is {pkgs.oatpp}/include/oatpp-1.3.0/oatpp/oatpp/etc... why???
    CXXFLAGS = "-I${pkgs.oatpp}/include/oatpp-1.3.0/oatpp";
}