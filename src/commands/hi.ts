import { Command } from "commander";
import chalk from "chalk";

import {error} from "../utils";

export function load(cmd : Command) {
    cmd
        .command("hi")
        .description("Este es solo un comando para saludar")
        .action(hi)
    ;
}

const hi = () => {
    console.log(chalk.bgBlue("Hi! This is DASM but in TypeScript"));
    console.log(error("Hola"));
}