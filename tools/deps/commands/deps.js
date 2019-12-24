//
// (c) LetsMakeGames 2019
// http://www.letsmake.games
//

const common = require('./common');
const git = require('./git');
const path = require('path');

//
// ############################################################################
//

const installFromConfig = async(cwd, config)=>{
  const installDir = path.join(cwd, config.project.installDir);
  const patchDir = path.join(cwd, config.project.patchDir);

  for(const name in config.dependencies) {
    const dep = config.dependencies[name];
    await git.clone(installDir, name, dep);

    const repoDir = path.join(installDir, name);
    const patchFile = path.join(patchDir, name);
    await git.applyPatch(repoDir, patchFile);
  }
}

//
// ----------------------------------------------------------------------------
//


const install = async(cwd, configfile)=>{
  const configpath = path.join(cwd, configfile);
  const config = await common.loadConfig(configpath);

  await installFromConfig(cwd, config);
}

//
// ----------------------------------------------------------------------------
//

const add = async(cwd, configfile, name, dep)=>{
  const configPath = path.join(cwd, configfile);
  const config = await common.loadConfig(configPath);

  config.dependencies[name] = dep;

  await installFromConfig(cwd, config);

  common.saveConfig(configPath, config);
}

//
// ////////////////////////////////////////////////////////////////////////////
//

module.exports = {
  install,
  add
}
