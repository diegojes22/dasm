"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.load = load;
const chalk_1 = __importDefault(require("chalk"));
const utils_1 = require("../utils");
function load(cmd) {
    cmd
        .command("hi")
        .description("Este es solo un comando para saludar")
        .action(hi);
}
const hi = () => {
    console.log(chalk_1.default.bgBlue("Hi! This is DASM but in TypeScript"));
    console.log((0, utils_1.error)("Hola"));
};
