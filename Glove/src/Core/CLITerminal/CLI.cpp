#include "CLI.h"

namespace CLITerminal {

    void Init(int argc, char** argv, bool debug)
    {
        Log::Logger c_logger;
        Log::Logger::LogSystem c_logSystem;

        c_logger.Init(false);
        if (debug == true)
            c_logSystem.Info("CLI Terminal Active!");

        CLI::App app{ "Glove CLI" };

        bool create = false;
        bool vscode = false;
        bool msvs = false;
        std::string projName;
        
        app.add_flag("--create", create, "Create a New Project");
        app.add_option("--name", projName, "Project Name")
            ->required()
            ->needs("--create");
        app.add_flag("--vscode", vscode, "Creates a VSCode Project")
            ->default_val(false)
            ->needs("--name");
        app.add_flag("--msvs", msvs, "Creates a MSVS Project")
            ->default_val(false)
            ->needs("--name");

        app.description("\nGlove is a lightweight, user-friendly C++ project manager designed to simplify development workflows. It streamlines dependency management, project setup, and compilation for both Visual Studio and VSCode environments. With support for YAML-based configuration, Glove ensures stability, ease of use, and customization, making C++ development faster and more efficient.");
        app.footer("Copyright (C) 2024 KyfStore11k - Glove");

        try {
            app.parse(argc, argv);
        }
        catch (const CLI::ParseError& e) {
            c_logSystem.Error("Failed to parse CLI arguments!");
            app.exit(e);
            return;
        }
        
        if (create)
        {
            if (!vscode && msvs || vscode && !msvs)
            {
                c_logSystem.Info("Creating project: " + projName);
            }
            else if (!vscode && !msvs) {
                c_logSystem.Error("Must include either one of these parameters: --vscode | --msvs");
            }
            else if (vscode && msvs) {
                c_logSystem.Error("Cannot include both parameters (--vscode and --msvs) at once!");
            }
        }
    }
}