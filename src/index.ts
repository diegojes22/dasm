import { Command } from "commander";
import { logo } from "./utils";
import chalk from "chalk";

import { ProgramController } from "./programController";

const root = new ProgramController(process.argv);
root.parser();