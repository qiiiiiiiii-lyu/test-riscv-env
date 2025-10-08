
local semihosting_specs = "/opt/riscv/riscv32-unknown-elf/lib/semihost.specs"

-- Define custom toolchain
toolchain("riscv32-unknown-elf")
    set_kind("standalone")

    set_toolset("cc", "riscv32-unknown-elf-gcc")
    set_toolset("cxx", "riscv32-unknown-elf-g++")
    set_toolset("ld", "riscv32-unknown-elf-g++")
    set_toolset("as", "riscv32-unknown-elf-as")

    on_load(function (toolchain)
        local default_flags = {
            "-march=rv32g",
            "-mabi=ilp32",
            "--specs=" .. semihosting_specs,
        }

        toolchain:add("cxflags", default_flags)
        toolchain:add("ldflags", default_flags)
    end)
toolchain_end()


add_rules("mode.debug")

set_project("heap-buffer-over-read")
set_version("1.0.0")

option("debug_run")
    set_default("false")
    set_showmenu(true)
    set_description("Run simulator in debug mode (-i)")

target("heap-buffer-over-read")
    set_kind("binary")
    set_toolchains("riscv32-unknown-elf")

    add_files("heap-buffer-over-read.cc")

    -- Output configs
    set_targetdir("build")
target_end()

on_run(function (target)
    local targetfile = target:targetfile()
    local simulator = "/usr/local/bin/mpact_rv32g_sim"
    local rundir = "../../submit-riscv/exercises-c++/01.heap-buffer-over-read/runs/run_" .. os.date("%Y%m%d_%H%M%S")
    os.mkdir(rundir)

    local args = {
        "--semihost_arm",
        "--output_dir=" .. rundir
    }
    if get_config("debug_run") == true then
        table.insert(args, "-i")
        
        
        print("Running in debug mode...")
        local log_file = "../../submit-riscv/exercises-c++/01.heap-buffer-over-read/debug"
        local log_time = os.date("%Y-%m-%d %H:%M:%S")
        local log_line = string.format("debug_time: %s\n", log_time)

        local f = io.open(log_file, "a")
        if f then
            f:write(log_line)
            f:close()
        end


    else
        print("Running in normal mode...")
    end
    table.insert(args, targetfile)
    os.execv(simulator, args)
end)

