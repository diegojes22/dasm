"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const programController_1 = require("./programController");
const root = new programController_1.ProgramController(process.argv);
root.parser();
