
local semihosting_specs = "/opt/riscv/riscv-none-elf/lib/semihost.specs"

-- Define custom toolchain
toolchain("riscv-none-elf")
    set_kind("standalone")

    set_toolset("cc", "riscv-none-elf-gcc")
    set_toolset("cxx", "riscv-none-elf-g++")
    set_toolset("ld", "riscv-none-elf-gcc")
    set_toolset("as", "riscv-none-elf-as")

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

set_project("stack-buffer-over-write")
set_version("1.0.0")

option("debug_run")
    set_default("false")
    set_showmenu(true)
    set_description("Run simulator in debug mode (-i)")

target("testing")
    set_kind("binary")
    set_toolchains("riscv-none-elf")

    add_files("stack-buffer-over-write.c")

    -- Output configs
    set_targetdir("build")
target_end()

on_run(function (target)
    local targetfile = target:targetfile()
    local simulator = "/usr/local/bin/mpact_rv32g_sim"
    local rundir = "./runs/run_" .. os.date("%Y%m%d_%H%M%S")

    local args = {
        "--semihost_arm",
        "--output_dir=" .. rundir
    }
    if get_config("debug_run") == true then
        table.insert(args, "-i")
        print("Running in debug mode...")
    else
        print("Running in normal mode...")
    end
    table.insert(args, targetfile)
    os.mkdir(rundir)
    os.execv(simulator, args)
end)

