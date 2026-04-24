import { Command } from "commander";
import { logo } from "./utils";
import chalk from "chalk";

import { AssemblerController } from "./assemblerController";

export class ProgramController {
    ///
    /// Atributos
    ///
    args : string[];
    cmd : Command;

    assemblerControler : AssemblerController;

    ///
    /// Metodos
    ///
    /**
     * Constructor
     * @param args 
     */
    constructor(args : string[]) {
        this.args = args;
        this.cmd = new Command();

        this.assemblerControler = new AssemblerController;

        this.cliBasics();
        this.addParams();
    }

    cliBasics() : void {
        this.cmd
            .name(chalk.bold("\n"+logo+"\n"))
            .description("Generador de plantillas de Turbo Ensamblador pero echo en TypeScript")
            .version("0.0.1 TS Edition")
        ;
    }

    addParams() : void {
        ///
        /// Agrega tus funcones definidas aqui para que el CLI las reconozca
        ///
        this.addOptions();
    }

    parser(): void {
        this.cmd.parse(this.args);
    }

    collect(value : any, previous : any) {
        return previous.concat([value]);
    }

    ///
    /// define tus funciones para el CLI a partir de aqui
    ///
    addOptions() : void {
        this.cmd
            .requiredOption("-f, --file <filepath>", "archivo para guardar la plantilla de turbo ensamblador")
            .option("-t, --template <template-name>", "tipo de platilla a seleccionar")
            .option("--variables <vars...>", "nombres de las variables a agregar en el programa")
            .option("-v, --variable <name>", "agregar una variable en el programa de ensamblador", this.collect, [])
            .option("--no-credits", "elimina los comentarios de los creditos para dejar un codigo base mas limpio")
            .option("--verbose", "imprimir mas detalle del proceso de creacion de la plantilla")
            .action((opt) => {
                this.assemblerControler.variables = [
                    ...(opt.variables ?? []),
                    ...(opt.variable  ?? [])
                ];

                console.log(`Variables Normalizadas: ${this.assemblerControler.variables}`);
            })
    }

    _prepareFilePath() : void {
        this.cmd
            .requiredOption("-f, --file <filepath>", "Nombre del archivo de turbo ensamblador a generar")
            .action((filepath) => {
                this.assemblerControler.filePath = filepath;
                console.log(`Preparando el archivo ${filepath}`);
            })
        ;
    }

    _define_template_type() : void {
        this.cmd
            .option('-t, --template <arg>', 'Seleccionar la plantilla para el archivo de Turbo Ensamblador')
            .action((arg) => {
                console.log('Opciones:', arg);
            })
        ;
    }


}