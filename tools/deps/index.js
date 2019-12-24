#!/usr/bin/env node

//
// (c) LetsMakeGames 2019
// http://www.letsmake.games
//

const commands = require('./commands');
const path = require('path');
const yargs = require('yargs');

const cwd = process.cwd();


//
// ############################################################################
//

yargs
  .scriptName('deps')
  .usage('$0 <cmd> [args]')

  //
  // install ------------------------------------------------------------------
  //
  
  .command('install', 'installs dependencies as described in the provided config file', (yargs)=>{
    yargs.option('config', { alias: 'c', type: 'string', default: 'deps.yml', describe: 'the deps file containing dependency configuration for this project'});
  }, async (argv)=>{
    await commands.deps.install(cwd, argv.config);
  })

  //
  // add ----------------------------------------------------------------------
  //

  .command('add [name] [repo]', 'adds and installs a new dependency to the project', (yargs)=>{
    yargs.positional('name', { type: 'string', describe: 'The name of the dependency'});
    yargs.positional('repo', { type: 'string', describe: 'The git repository path to the desired dependency'});
    yargs.option('tag', { type: 'string', describe: 'The git tag this dependency should be tracked at'});
    yargs.option('sha', { type: 'string', describe: 'The git sha tag for the commit this dependency should be tracked at'});
    yargs.option('config', { alias: 'c', type: 'string', default: 'deps.yml', describe: 'the deps file containing dependency configuration for this project'});
  }, async (argv)=>{
    const dep = {
      repo: argv.repo,
      tag: argv.tag,
      sha: argv.sha
    };

    await commands.deps.add(cwd, argv.config, argv.name, dep);
  })

  //
  // patch --------------------------------------------------------------------
  //

  .command('patch [name]', 'creates a new patch in the dependency with name using project configuration provided', (yargs)=>{
    yargs.positional('name', { type: 'string', describe: 'The name of the dependency to generate a patch from'});
    yargs.option('config', { alias: 'c', type: 'string', default: 'deps.yml', describe: 'the deps file containing dependency configuration for this project'});
  }, async (argv)=>{
    await commands.git.createPatch(cwd, argv.config, argv.name);  
  })
  
  
  //
  // ------------------------------------------------------------------------
  //
  
  .help()
  .showHelpOnFail()
  .demandCommand()
  .argv
