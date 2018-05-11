--------------------------------------------------------------------------------
-- Copyright (c) 1995-2007 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: J.36
--  \   \         Application: netgen
--  /   /         Filename: my_xor6_gate_synthesis.vhd
-- /___/   /\     Timestamp: Wed Mar 25 10:32:54 2015
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -ar Structure -tm my_xor6_gate -w -dir netgen/synthesis -ofmt vhdl -sim my_xor6_gate.ngc my_xor6_gate_synthesis.vhd 
-- Device	: xc3s500e-4-fg320
-- Input file	: my_xor6_gate.ngc
-- Output file	: \\fileserver.eecs.ku.edu\raviles\EECS140Lab8\netgen\synthesis\my_xor6_gate_synthesis.vhd
-- # of Entities	: 1
-- Design Name	: my_xor6_gate
-- Xilinx	: C:\Xilinx92i
--             
-- Purpose:    
--     This VHDL netlist is a verification model and uses simulation 
--     primitives which may not represent the true implementation of the 
--     device, however the netlist is functionally correct and should not 
--     be modified. This file cannot be synthesized and should only be used 
--     with supported simulation tools.
--             
-- Reference:  
--     Development System Reference Guide, Chapter 23
--     Synthesis and Simulation Design Guide, Chapter 6
--             
--------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
use UNISIM.VPKG.ALL;

entity my_xor6_gate is
  port (
    R : out STD_LOGIC; 
    U : in STD_LOGIC := 'X'; 
    V : in STD_LOGIC := 'X'; 
    W : in STD_LOGIC := 'X'; 
    X : in STD_LOGIC := 'X'; 
    Y : in STD_LOGIC := 'X'; 
    Z : in STD_LOGIC := 'X' 
  );
end my_xor6_gate;

architecture Structure of my_xor6_gate is
  signal R_OBUF_0 : STD_LOGIC; 
  signal U_IBUF_1 : STD_LOGIC; 
  signal V_IBUF_2 : STD_LOGIC; 
  signal W_IBUF_3 : STD_LOGIC; 
  signal X_IBUF_4 : STD_LOGIC; 
  signal Y_IBUF_5 : STD_LOGIC; 
  signal Z_IBUF_6 : STD_LOGIC; 
  signal XxorYxorZ : STD_LOGIC; 
  signal N2 : STD_LOGIC; 
  signal N3 : STD_LOGIC; 
begin
  XYZ_GATE2_C1 : LUT3
    generic map(
      INIT => X"96"
    )
    port map (
      I0 => Y_IBUF_5,
      I1 => Z_IBUF_6,
      I2 => X_IBUF_4,
      O => XxorYxorZ
    );
  UVWXYZ_C1 : LUT4
    generic map(
      INIT => X"6996"
    )
    port map (
      I0 => W_IBUF_3,
      I1 => XxorYxorZ,
      I2 => U_IBUF_1,
      I3 => V_IBUF_2,
      O => R_OBUF_0
    );
  U_IBUF : IBUF
    port map (
      I => U,
      O => U_IBUF_1
    );
  V_IBUF : IBUF
    port map (
      I => V,
      O => V_IBUF_2
    );
  W_IBUF : IBUF
    port map (
      I => W,
      O => W_IBUF_3
    );
  X_IBUF : IBUF
    port map (
      I => X,
      O => X_IBUF_4
    );
  Y_IBUF : IBUF
    port map (
      I => Y,
      O => Y_IBUF_5
    );
  Z_IBUF : IBUF
    port map (
      I => Z,
      O => Z_IBUF_6
    );
  R_OBUF : OBUF
    port map (
      I => R_OBUF_0,
      O => R
    );
  XST_VCC : VCC
    port map (
      P => N2
    );
  XST_GND : GND
    port map (
      G => N3
    );

end Structure;

