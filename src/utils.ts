import chalk from "chalk";
import figlet from "figlet";

export const logo = figlet.textSync("DASM - TS edition", {font: "slant"});

export const error = chalk.bold.red;
export const warning = chalk.bold.yellowBright;

