//
// (c) LetsMakeGames 2019
// http://www.letsmake.games
//

const fs = require('fs-extra');
const yml = require('yaml-js');

//
// ############################################################################
//

const loadConfig = async(configpath)=>{
  const configstr = await fs.readFile(configpath, 'utf-8');
  return yml.load(configstr);
}


//
// ------------------------------------------------------------------------
//

const saveConfig = async(configpath, config)=>{
  // sanitize config
  for(name in config.dependencies) {
    const dep = config.dependencies[name];
    if(!dep.tag) delete dep.tag;
    if(!dep.sha) delete dep.sha;
  }
  await fs.writeFile(configpath, yml.dump(config));
}

//
// ////////////////////////////////////////////////////////////////////////////
//


module.exports = {
  loadConfig,
  saveConfig
}
