"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.warning = exports.error = exports.logo = void 0;
const chalk_1 = __importDefault(require("chalk"));
const figlet_1 = __importDefault(require("figlet"));
exports.logo = figlet_1.default.textSync("DASM - TS edition", { font: "slant" });
exports.error = chalk_1.default.bold.red;
exports.warning = chalk_1.default.bold.yellowBright;
