# Engine

## Windows Quickstart Guide

### Bootstrapping
In order to build and run this project on Windows a few utilities should be
downloaded and installed before beginning.

You will need:
- (Visual Studio 2019 Community Edition)[https://visualstudio.microsoft.com/]
  - Ensure the Desktop development with C++ is enabled
- (CMake v3.16.0)[https://cmake.org/download/] or newer 
- (Chocolatey)[https://chocolatey.org/install]

- Using chocolatey in an administrator elevated powershell, install nodejs
    - `choco install nodejs` this should install v13.5.0 or newer

- Using chocolatey in an adminstrator elevated powershell, install git
    - `choco install git`

- You may need to install ssh utils in powershell to be able to use ssh keys in
  order to clone the repository.
    - `Install-Module -Force OpenSSHUtils -Scope AllUsers` - this adds the OpenSSH service
    - `Get-Service -Name ssh-agent | Set-Service -StartupType Manual` - this sets the service to startup manually
    - `Service-Start ssh-agent` - this starts the agent
    - Add ssh key

- (optional) from powershell terminal
  - `set-executionpolicy remotesigned` allows you to run our script
  - `.\tools\boostrap.ps1` makes softlinks to `build.bat` and `bench.bat` for convenience

## TODO

- Improve `boostrap.ps1` to install chocolatey, git, and node.
- Test and verify deps tools on windows.

### Linux Subsystem for Windows
Thanks to CMake building out of tree, it is possible to sync and manage the tool
using the Linux Subsystem for Windows, and use PowerShell only for executing the
builds.

You will need:
- Visual Studio 2019
- CMake

- It is recommended you use deps and nodejs from the linux subsystem.

- You can trigger builds by calling the batch file directly `.\tools\win\cbuild.bat`

- Work on the `bootstrap.ps1` file is underway to make it as automagical as the
  linux version.
