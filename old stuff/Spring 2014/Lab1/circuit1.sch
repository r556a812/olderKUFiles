VERSION 6
BEGIN SCHEMATIC
    BEGIN ATTR DeviceFamilyName "spartan3e"
        DELETE all:0
        EDITNAME all:0
        EDITTRAIT all:0
    END ATTR
    BEGIN NETLIST
        SIGNAL XLXN_1
        SIGNAL A
        SIGNAL B
        SIGNAL C
        SIGNAL Y
        SIGNAL XLXN_8
        SIGNAL XLXN_9
        PORT Input A
        PORT Input B
        PORT Input C
        PORT Output Y
        BEGIN BLOCKDEF and2
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -64 64 -64 
            LINE N 0 -128 64 -128 
            LINE N 256 -96 192 -96 
            ARC N 96 -144 192 -48 144 -48 144 -144 
            LINE N 144 -48 64 -48 
            LINE N 64 -144 144 -144 
            LINE N 64 -48 64 -144 
        END BLOCKDEF
        BEGIN BLOCKDEF or2
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -64 64 -64 
            LINE N 0 -128 64 -128 
            LINE N 256 -96 192 -96 
            ARC N 28 -224 204 -48 112 -48 192 -96 
            ARC N -40 -152 72 -40 48 -48 48 -144 
            LINE N 112 -144 48 -144 
            ARC N 28 -144 204 32 192 -96 112 -144 
            LINE N 112 -48 48 -48 
        END BLOCKDEF
        BEGIN BLOCK XLXI_1 and2
            PIN I0 B
            PIN I1 A
            PIN O XLXN_1
        END BLOCK
        BEGIN BLOCK XLXI_2 or2
            PIN I0 C
            PIN I1 XLXN_1
            PIN O Y
        END BLOCK
    END NETLIST
    BEGIN SHEET 1 3520 2720
        INSTANCE XLXI_1 1040 896 R0
        BEGIN BRANCH A
            WIRE 1008 768 1040 768
        END BRANCH
        IOMARKER 1008 768 A R180 28
        BEGIN BRANCH B
            WIRE 1008 832 1040 832
        END BRANCH
        IOMARKER 1008 832 B R180 28
        BEGIN BRANCH C
            WIRE 1008 960 1472 960
            WIRE 1472 960 1488 960
        END BRANCH
        BEGIN BRANCH Y
            WIRE 1744 928 1760 928
            WIRE 1760 928 1776 928
        END BRANCH
        INSTANCE XLXI_2 1488 1024 R0
        BEGIN BRANCH XLXN_1
            WIRE 1296 800 1312 800
            WIRE 1312 800 1312 896
            WIRE 1312 896 1488 896
        END BRANCH
        IOMARKER 1008 960 C R180 28
        IOMARKER 1776 928 Y R0 28
    END SHEET
END SCHEMATIC
