import { Command } from "commander";
import { logo } from "./utils";

const hi = require("./commands/hi");

const program = new Command();

program
    .name(logo)
;

hi.load(program);

program.parse(process.argv);