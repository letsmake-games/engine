# Engine

## Linux Quickstart Guide

All commands should be executed in the root of the repository.

### Bootstrapping
- Bootstrap using `./tools/bootstrap.sh`
- It will prompt several options
  - Whether or not you want to update system dependencies (requires `sudo`) as
    well as additional modules needed for building (`ninja-build`, `build-essentials`
    etc)
  - Whether or not you want to install cmake.
    - If you do install cmake, and make use of the auto update to your `.bash_profile`
      file, ensure that cmake is available by running `source ~/.bash_profile`.
    - You can ensure that things are properly setup by running `cmake --version`
  - Whether or not you want to install Node Version Manager
    - Many tools and utilities require having a verison of node installed, NVM
      allows you to have a local installation for this repository, so it is highly
      recommended.  Otherwise, you can use or alias the `node` command to any
      locally installed node version you prefer.
    - It is highly recommended, however, you leverage NVM to manage your node
      versions.
    - This repository depends on node version 12.13.0 (erbium LTS)
  - Whether or not you want to build convenient softlinks to tools in the root
    of the repository.  Doing this prevents you from needing to preface all of you
    command commands with `./tools/`.  For example, `./tools/deps/index.js` becomes
    simply `./deps`.

These steps may be completely skipped and handled manually.  Feel free to read
the bootstrap shell script (it is well commented!) to understand exactly what
it is doing.

### Dependencies

- Dependencies are managed using the `./deps` tool.  `./deps --help` prints all
  available commands.
  - Common commands include:
    - `./deps install` which will use the `./deps.yml` file to locate and install
    - `./deps add` allows you to add new dependencies to the project.
    - `./deps patch` allows you to modify dependencies in tree, then generate a
       patch file which can be checked in and will be applied on subsequent
       `./deps install` calls.

### Patching

In order to generate a custom patch after installing dependencies into the extern
folder, navigate to that location and modify the repository as required.

Once you've made the changes you'd like to persist, simply call `./deps patch [depname]`

For example, if modifying google test library, you would make the desired changes
then call `./deps patch gtest`.  This will generate a new file `./patches/gtest`
containing a text representation of the changes made (in the form of a `git diff`)

Check this patch file in.

Next time someone pulls the repository and runs `./deps install` this patch will
be applied locally for them as well.

### Building
- Before building, you must install dependencies using the `./deps` tool, as
  described in the previous section.

- You can build using the `./build` command, or by calling the shell script
  directly in ``./tools/build/linux/cbuild.sh`

- Build will generate libraries with debug symbols as well as execute tests
  automatically.

- You can also build using a benchmark build using `./bench`.  This will build
  an optimized build as well as run any benchmarks.
