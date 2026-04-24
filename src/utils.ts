import chalk from "chalk";
const figlet = require("figlet");

export const logo = figlet.textSync("DASM - TS edition", {font: "slant"});

export const error = chalk.bold.red;
export const warning = chalk.bold.yellowBright;