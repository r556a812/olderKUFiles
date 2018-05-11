--------------------------------------------------------------------------------
-- Copyright (c) 1995-2007 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 9.2i
--  \   \         Application : sch2vhdl
--  /   /         Filename : Lab2Schematic.vhf
-- /___/   /\     Timestamp : 02/04/2015 10:15:10
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: C:\Xilinx92i\bin\nt\sch2vhdl.exe -intstyle ise -family spartan3e -flat -suppress -w H:/Lab2/Lab2Schematic.sch Lab2Schematic.vhf
--Design Name: Lab2Schematic
--Device: spartan3e
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesis and simulted, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity Lab2Schematic is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          Y : out   std_logic);
end Lab2Schematic;

architecture BEHAVIORAL of Lab2Schematic is
   attribute BOX_TYPE   : string ;
   signal XLXN_1  : std_logic;
   signal XLXN_2  : std_logic;
   signal XLXN_3  : std_logic;
   signal XLXN_4  : std_logic;
   signal XLXN_11 : std_logic;
   signal XLXN_12 : std_logic;
   component AND3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND3 : component is "BLACK_BOX";
   
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component OR3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR3 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND3
      port map (I0=>C,
                I1=>XLXN_12,
                I2=>A,
                O=>XLXN_1);
   
   XLXI_2 : AND2
      port map (I0=>XLXN_11,
                I1=>B,
                O=>XLXN_3);
   
   XLXI_3 : OR3
      port map (I0=>XLXN_3,
                I1=>XLXN_2,
                I2=>XLXN_1,
                O=>Y);
   
   XLXI_4 : AND2
      port map (I0=>XLXN_12,
                I1=>XLXN_4,
                O=>XLXN_2);
   
   XLXI_5 : INV
      port map (I=>B,
                O=>XLXN_12);
   
   XLXI_9 : INV
      port map (I=>A,
                O=>XLXN_4);
   
   XLXI_10 : INV
      port map (I=>C,
                O=>XLXN_11);
   
end BEHAVIORAL;


