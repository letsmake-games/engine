//
// (c) LetsMakeGames 2019
// http://www.letsmake.games
//

const fs = require('fs-extra');
const git = require('simple-git/promise');
const path = require('path');

//
// ############################################################################
//

//
// apply patch ----------------------------------------------------------------
//

const applyPatch = async(repoDir, patchFile)=>{
  if(fs.existsSync(patchFile)) {
    const repo = git(repoDir);
    await repo.raw([
      'apply',
      patchFile
    ]);
  }
}

//
// create patch ---------------------------------------------------------------
//

const createPatch = async(repoDir, patchPath)=>{
  const repo = git(repoDir);
  const diff = await repo.diff();
  
  if(diff) {
    const patchDir = path.dirname(patchPath);
    await fs.ensureDir(patchDir);
    await fs.writeFile(patchPath, diff, 'utf-8');
  }
}

//
// clone ----------------------------------------------------------------------
//

const clone = async(installDir, name, dep)=>{
  console.log(`---Installing ${name}...`);
  const root = git(installDir);

  const installPath = path.join(installDir, name);
  if(!fs.existsSync(installPath)) {
    await root.clone(dep.repo, name);
  }

  const repo = git(installPath);
  if(dep.tag) {
    repo.checkout(dep.tag);
  }
  else if(dep.sha) {
    repo.checkout(dep.sha);
  }
}

//
// diff -----------------------------------------------------------------------
//

const diff = async(dir)=>{
  const repo = git(dir);
  return await repo.diff();
}

//
// ////////////////////////////////////////////////////////////////////////////
//


module.exports = {
  applyPatch,
  clone,
  createPatch,
  diff,
}
