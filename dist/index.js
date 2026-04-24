"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const commander_1 = require("commander");
const utils_1 = require("./utils");
const hi = require("./commands/hi");
const program = new commander_1.Command();
program
    .name(utils_1.logo);
hi.load(program);
program.parse(process.argv);
