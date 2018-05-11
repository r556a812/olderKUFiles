VERSION 6
BEGIN SCHEMATIC
    BEGIN ATTR DeviceFamilyName "spartan3e"
        DELETE all:0
        EDITNAME all:0
        EDITTRAIT all:0
    END ATTR
    BEGIN NETLIST
        SIGNAL XLXN_1
        SIGNAL C
        SIGNAL D
        SIGNAL B
        SIGNAL A
        SIGNAL Y
        SIGNAL XLXN_7
        SIGNAL XLXN_8
        SIGNAL XLXN_9
        SIGNAL XLXN_10
        SIGNAL XLXN_11
        SIGNAL XLXN_12
        SIGNAL XLXN_13
        PORT Input C
        PORT Input D
        PORT Input B
        PORT Input A
        PORT Output Y
        BEGIN BLOCKDEF circuit1
            TIMESTAMP 2015 1 28 15 33 48
            RECTANGLE N 64 -192 320 0 
            LINE N 64 -160 0 -160 
            LINE N 64 -96 0 -96 
            LINE N 64 -32 0 -32 
            LINE N 320 -160 384 -160 
        END BLOCKDEF
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
        BEGIN BLOCK XLXI_1 circuit1
            PIN A A
            PIN B B
            PIN C XLXN_1
            PIN Y Y
        END BLOCK
        BEGIN BLOCK XLXI_2 and2
            PIN I0 D
            PIN I1 C
            PIN O XLXN_1
        END BLOCK
    END NETLIST
    BEGIN SHEET 1 3520 2720
        BEGIN INSTANCE XLXI_1 1024 896 R0
        END INSTANCE
        BEGIN BRANCH XLXN_1
            WIRE 928 864 1024 864
        END BRANCH
        BEGIN BRANCH C
            WIRE 624 832 656 832
            WIRE 656 832 672 832
        END BRANCH
        BEGIN BRANCH D
            WIRE 624 896 656 896
            WIRE 656 896 672 896
        END BRANCH
        BEGIN BRANCH B
            WIRE 624 784 1008 784
            WIRE 1008 784 1008 800
            WIRE 1008 800 1024 800
        END BRANCH
        BEGIN BRANCH A
            WIRE 624 736 1008 736
            WIRE 1008 736 1024 736
        END BRANCH
        BEGIN BRANCH Y
            WIRE 1408 736 1440 736
        END BRANCH
        IOMARKER 1440 736 Y R0 28
        IOMARKER 624 736 A R180 28
        INSTANCE XLXI_2 672 960 R0
        IOMARKER 624 784 B R180 28
        IOMARKER 624 832 C R180 28
        IOMARKER 624 896 D R180 28
    END SHEET
END SCHEMATIC
