{
  description = "Basic flake template";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {


        devShell = with pkgs; mkShell {
          shellHook = ''

          '';
          buildInputs = with pkgs; [
            gcc
            cmake
            clang-tools
            pkg-config

            SDL2
            libxkbcommon
            wayland
            wayland-protocols
            libffi
            xorg.libX11
            xorg.libX11.dev
            xorg.libXft
            xorg.libXfixes
            xorg.libXScrnSaver
            xorg.libXi
            xorg.libXcursor
            xorg.libXrandr
            xorg.libXrender
            xorg.libXext
            xorg.libxcb
            xorg.libXau
            xorg.libXdmcp
          ];
        };
      });
}
