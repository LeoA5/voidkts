{ pkgs? import <nixpkgs> {} }:

pkgs.mkShell{
    packages = [ pkgs.python315 pkgs.libgcc ];
    shellHook = ''
        good morning!
    '';
}