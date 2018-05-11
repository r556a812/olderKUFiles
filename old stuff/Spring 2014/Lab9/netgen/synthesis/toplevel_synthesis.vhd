--------------------------------------------------------------------------------
-- Copyright (c) 1995-2007 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: J.36
--  \   \         Application: netgen
--  /   /         Filename: toplevel_synthesis.vhd
-- /___/   /\     Timestamp: Wed Apr 01 10:22:11 2015
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -ar Structure -tm toplevel -w -dir netgen/synthesis -ofmt vhdl -sim toplevel.ngc toplevel_synthesis.vhd 
-- Device	: xc3s500e-4-fg320
-- Input file	: toplevel.ngc
-- Output file	: \\fileserver.eecs.ku.edu\raviles\Lab9\netgen\synthesis\toplevel_synthesis.vhd
-- # of Entities	: 1
-- Design Name	: toplevel
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

entity toplevel is
  port (
    clk : in STD_LOGIC := 'X'; 
    carry_in : in STD_LOGIC := 'X'; 
    an : out STD_LOGIC_VECTOR ( 0 to 3 ); 
    seg : out STD_LOGIC_VECTOR ( 6 downto 0 ); 
    SW : in STD_LOGIC_VECTOR ( 7 downto 0 ) 
  );
end toplevel;

architecture Structure of toplevel is
  signal clk_BUFGP_0 : STD_LOGIC; 
  signal carry_in_IBUF_1 : STD_LOGIC; 
  signal c3 : STD_LOGIC; 
  signal s0 : STD_LOGIC; 
  signal s1 : STD_LOGIC; 
  signal s2 : STD_LOGIC; 
  signal s3 : STD_LOGIC; 
  signal c0 : STD_LOGIC; 
  signal c1 : STD_LOGIC; 
  signal c2 : STD_LOGIC; 
  signal an_0_OBUF_2 : STD_LOGIC; 
  signal an_1_OBUF_3 : STD_LOGIC; 
  signal an_2_OBUF_4 : STD_LOGIC; 
  signal an_3_OBUF_5 : STD_LOGIC; 
  signal seg_6_OBUF_6 : STD_LOGIC; 
  signal seg_5_OBUF_7 : STD_LOGIC; 
  signal seg_4_OBUF_8 : STD_LOGIC; 
  signal seg_3_OBUF_9 : STD_LOGIC; 
  signal seg_2_OBUF_10 : STD_LOGIC; 
  signal seg_1_OBUF_11 : STD_LOGIC; 
  signal seg_0_OBUF_12 : STD_LOGIC; 
  signal SW_7_IBUF_13 : STD_LOGIC; 
  signal SW_6_IBUF_14 : STD_LOGIC; 
  signal SW_5_IBUF_15 : STD_LOGIC; 
  signal SW_4_IBUF_16 : STD_LOGIC; 
  signal SW_3_IBUF_17 : STD_LOGIC; 
  signal SW_2_IBUF_18 : STD_LOGIC; 
  signal SW_1_IBUF_19 : STD_LOGIC; 
  signal SW_0_IBUF_20 : STD_LOGIC; 
  signal LEDdisplay1_cur_state_FFd1_21 : STD_LOGIC; 
  signal LEDdisplay1_cur_state_FFd2_22 : STD_LOGIC; 
  signal display_driver1_Mrom_seg_out1 : STD_LOGIC; 
  signal display_driver1_Mrom_seg_out6 : STD_LOGIC; 
  signal display_driver0_Mrom_seg_out : STD_LOGIC; 
  signal display_driver0_Mrom_seg_out1 : STD_LOGIC; 
  signal display_driver0_Mrom_seg_out2 : STD_LOGIC; 
  signal display_driver0_Mrom_seg_out3 : STD_LOGIC; 
  signal display_driver0_Mrom_seg_out4 : STD_LOGIC; 
  signal display_driver0_Mrom_seg_out5 : STD_LOGIC; 
  signal display_driver0_Mrom_seg_out6 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_1_rt_23 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_2_rt_24 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_3_rt_25 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_4_rt_26 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_5_rt_27 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_6_rt_28 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_7_rt_29 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_8_rt_30 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_9_rt_31 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_10_rt_32 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_11_rt_33 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_12_rt_34 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_cy_13_rt_35 : STD_LOGIC; 
  signal LEDdisplay1_Mcount_Counter_Signal_xor_14_rt_36 : STD_LOGIC; 
  signal N39 : STD_LOGIC; 
  signal N40 : STD_LOGIC; 
  signal N41 : STD_LOGIC; 
  signal LEDdisplay1_control : STD_LOGIC_VECTOR ( 0 downto 0 ); 
  signal LEDdisplay1_Counter_Signal : STD_LOGIC_VECTOR ( 14 downto 0 ); 
  signal Result : STD_LOGIC_VECTOR ( 14 downto 0 ); 
  signal LEDdisplay1_Mcount_Counter_Signal_cy : STD_LOGIC_VECTOR ( 13 downto 0 ); 
  signal LEDdisplay1_dispMUX00_seg1 : STD_LOGIC_VECTOR ( 6 downto 0 ); 
  signal LEDdisplay1_dispMUX00_seg0 : STD_LOGIC_VECTOR ( 6 downto 0 ); 
begin
  XST_VCC : VCC
    port map (
      P => display_driver1_Mrom_seg_out6
    );
  XST_GND : GND
    port map (
      G => display_driver1_Mrom_seg_out1
    );
  LEDdisplay1_cur_state_FFd1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => LEDdisplay1_Counter_Signal(14),
      D => LEDdisplay1_cur_state_FFd2_22,
      Q => LEDdisplay1_cur_state_FFd1_21
    );
  LEDdisplay1_Counter_Signal_0 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(0),
      Q => LEDdisplay1_Counter_Signal(0)
    );
  LEDdisplay1_Counter_Signal_1 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(1),
      Q => LEDdisplay1_Counter_Signal(1)
    );
  LEDdisplay1_Counter_Signal_2 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(2),
      Q => LEDdisplay1_Counter_Signal(2)
    );
  LEDdisplay1_Counter_Signal_3 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(3),
      Q => LEDdisplay1_Counter_Signal(3)
    );
  LEDdisplay1_Counter_Signal_4 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(4),
      Q => LEDdisplay1_Counter_Signal(4)
    );
  LEDdisplay1_Counter_Signal_5 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(5),
      Q => LEDdisplay1_Counter_Signal(5)
    );
  LEDdisplay1_Counter_Signal_6 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(6),
      Q => LEDdisplay1_Counter_Signal(6)
    );
  LEDdisplay1_Counter_Signal_7 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(7),
      Q => LEDdisplay1_Counter_Signal(7)
    );
  LEDdisplay1_Counter_Signal_8 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(8),
      Q => LEDdisplay1_Counter_Signal(8)
    );
  LEDdisplay1_Counter_Signal_9 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(9),
      Q => LEDdisplay1_Counter_Signal(9)
    );
  LEDdisplay1_Counter_Signal_10 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(10),
      Q => LEDdisplay1_Counter_Signal(10)
    );
  LEDdisplay1_Counter_Signal_11 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(11),
      Q => LEDdisplay1_Counter_Signal(11)
    );
  LEDdisplay1_Counter_Signal_12 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(12),
      Q => LEDdisplay1_Counter_Signal(12)
    );
  LEDdisplay1_Counter_Signal_13 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(13),
      Q => LEDdisplay1_Counter_Signal(13)
    );
  LEDdisplay1_Counter_Signal_14 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(14),
      Q => LEDdisplay1_Counter_Signal(14)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_0_Q : MUXCY
    port map (
      CI => display_driver1_Mrom_seg_out1,
      DI => display_driver1_Mrom_seg_out6,
      S => Result(0),
      O => LEDdisplay1_Mcount_Counter_Signal_cy(0)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_1_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(0),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_1_rt_23,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(1)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_1_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(0),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_1_rt_23,
      O => Result(1)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_2_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(1),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_2_rt_24,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(2)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_2_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(1),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_2_rt_24,
      O => Result(2)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_3_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(2),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_3_rt_25,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(3)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_3_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(2),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_3_rt_25,
      O => Result(3)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_4_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(3),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_4_rt_26,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(4)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_4_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(3),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_4_rt_26,
      O => Result(4)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_5_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(4),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_5_rt_27,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(5)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_5_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(4),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_5_rt_27,
      O => Result(5)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_6_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(5),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_6_rt_28,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(6)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_6_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(5),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_6_rt_28,
      O => Result(6)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_7_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(6),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_7_rt_29,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(7)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_7_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(6),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_7_rt_29,
      O => Result(7)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_8_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(7),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_8_rt_30,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(8)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_8_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(7),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_8_rt_30,
      O => Result(8)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_9_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(8),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_9_rt_31,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(9)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_9_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(8),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_9_rt_31,
      O => Result(9)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_10_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(9),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_10_rt_32,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(10)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_10_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(9),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_10_rt_32,
      O => Result(10)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_11_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(10),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_11_rt_33,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(11)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_11_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(10),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_11_rt_33,
      O => Result(11)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_12_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(11),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_12_rt_34,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(12)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_12_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(11),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_12_rt_34,
      O => Result(12)
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_13_Q : MUXCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(12),
      DI => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_Mcount_Counter_Signal_cy_13_rt_35,
      O => LEDdisplay1_Mcount_Counter_Signal_cy(13)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_13_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(12),
      LI => LEDdisplay1_Mcount_Counter_Signal_cy_13_rt_35,
      O => Result(13)
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_14_Q : XORCY
    port map (
      CI => LEDdisplay1_Mcount_Counter_Signal_cy(13),
      LI => LEDdisplay1_Mcount_Counter_Signal_xor_14_rt_36,
      O => Result(14)
    );
  LEDdisplay1_dispMUX00_dispMUX62 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(6),
      I1 => LEDdisplay1_dispMUX00_seg1(6),
      S => LEDdisplay1_cur_state_FFd1_21,
      O => seg_6_OBUF_6
    );
  LEDdisplay1_dispMUX00_dispMUX61 : MUXF5
    port map (
      I0 => display_driver1_Mrom_seg_out6,
      I1 => display_driver1_Mrom_seg_out6,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(6)
    );
  LEDdisplay1_dispMUX00_dispMUX60 : MUXF5
    port map (
      I0 => display_driver0_Mrom_seg_out6,
      I1 => display_driver1_Mrom_seg_out6,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(6)
    );
  LEDdisplay1_dispMUX00_dispMUX52 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(5),
      I1 => LEDdisplay1_dispMUX00_seg1(5),
      S => LEDdisplay1_cur_state_FFd1_21,
      O => seg_5_OBUF_7
    );
  LEDdisplay1_dispMUX00_dispMUX51 : MUXF5
    port map (
      I0 => display_driver1_Mrom_seg_out6,
      I1 => display_driver1_Mrom_seg_out6,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(5)
    );
  LEDdisplay1_dispMUX00_dispMUX50 : MUXF5
    port map (
      I0 => display_driver0_Mrom_seg_out5,
      I1 => N39,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(5)
    );
  LEDdisplay1_dispMUX00_dispMUX42 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(4),
      I1 => LEDdisplay1_dispMUX00_seg1(4),
      S => LEDdisplay1_cur_state_FFd1_21,
      O => seg_4_OBUF_8
    );
  LEDdisplay1_dispMUX00_dispMUX41 : MUXF5
    port map (
      I0 => display_driver1_Mrom_seg_out6,
      I1 => display_driver1_Mrom_seg_out6,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(4)
    );
  LEDdisplay1_dispMUX00_dispMUX40 : MUXF5
    port map (
      I0 => display_driver0_Mrom_seg_out4,
      I1 => N40,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(4)
    );
  LEDdisplay1_dispMUX00_dispMUX32 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(3),
      I1 => LEDdisplay1_dispMUX00_seg1(3),
      S => LEDdisplay1_cur_state_FFd1_21,
      O => seg_3_OBUF_9
    );
  LEDdisplay1_dispMUX00_dispMUX31 : MUXF5
    port map (
      I0 => display_driver1_Mrom_seg_out6,
      I1 => display_driver1_Mrom_seg_out6,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(3)
    );
  LEDdisplay1_dispMUX00_dispMUX30 : MUXF5
    port map (
      I0 => display_driver0_Mrom_seg_out3,
      I1 => N41,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(3)
    );
  LEDdisplay1_dispMUX00_dispMUX22 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(2),
      I1 => LEDdisplay1_dispMUX00_seg1(2),
      S => LEDdisplay1_cur_state_FFd1_21,
      O => seg_2_OBUF_10
    );
  LEDdisplay1_dispMUX00_dispMUX21 : MUXF5
    port map (
      I0 => display_driver1_Mrom_seg_out6,
      I1 => display_driver1_Mrom_seg_out6,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(2)
    );
  LEDdisplay1_dispMUX00_dispMUX20 : MUXF5
    port map (
      I0 => display_driver0_Mrom_seg_out2,
      I1 => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(2)
    );
  LEDdisplay1_dispMUX00_dispMUX12 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(1),
      I1 => LEDdisplay1_dispMUX00_seg1(1),
      S => LEDdisplay1_cur_state_FFd1_21,
      O => seg_1_OBUF_11
    );
  LEDdisplay1_dispMUX00_dispMUX11 : MUXF5
    port map (
      I0 => display_driver1_Mrom_seg_out6,
      I1 => display_driver1_Mrom_seg_out6,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(1)
    );
  LEDdisplay1_dispMUX00_dispMUX10 : MUXF5
    port map (
      I0 => display_driver0_Mrom_seg_out1,
      I1 => display_driver1_Mrom_seg_out1,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(1)
    );
  LEDdisplay1_dispMUX00_dispMUX02 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(0),
      I1 => LEDdisplay1_dispMUX00_seg1(0),
      S => LEDdisplay1_cur_state_FFd1_21,
      O => seg_0_OBUF_12
    );
  LEDdisplay1_dispMUX00_dispMUX01 : MUXF5
    port map (
      I0 => display_driver1_Mrom_seg_out6,
      I1 => display_driver1_Mrom_seg_out6,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(0)
    );
  LEDdisplay1_dispMUX00_dispMUX00 : MUXF5
    port map (
      I0 => display_driver0_Mrom_seg_out,
      I1 => c3,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(0)
    );
  LEDdisplay1_cur_state_Out51 : LUT2
    generic map(
      INIT => X"E"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd1_21,
      I1 => LEDdisplay1_cur_state_FFd2_22,
      O => an_3_OBUF_5
    );
  LEDdisplay1_cur_state_Out41 : LUT2
    generic map(
      INIT => X"D"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd2_22,
      I1 => LEDdisplay1_cur_state_FFd1_21,
      O => an_2_OBUF_4
    );
  LEDdisplay1_cur_state_Out31 : LUT2
    generic map(
      INIT => X"7"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd2_22,
      I1 => LEDdisplay1_cur_state_FFd1_21,
      O => an_1_OBUF_3
    );
  LEDdisplay1_cur_state_Out21 : LUT2
    generic map(
      INIT => X"D"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd1_21,
      I1 => LEDdisplay1_cur_state_FFd2_22,
      O => an_0_OBUF_2
    );
  LEDdisplay1_cur_state_Out11 : LUT2
    generic map(
      INIT => X"6"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd2_22,
      I1 => LEDdisplay1_cur_state_FFd1_21,
      O => LEDdisplay1_control(0)
    );
  adder3_Cout1 : LUT3
    generic map(
      INIT => X"E8"
    )
    port map (
      I0 => SW_3_IBUF_17,
      I1 => SW_7_IBUF_13,
      I2 => c2,
      O => c3
    );
  adder2_Cout1 : LUT3
    generic map(
      INIT => X"E8"
    )
    port map (
      I0 => SW_2_IBUF_18,
      I1 => SW_6_IBUF_14,
      I2 => c1,
      O => c2
    );
  adder1_Cout1 : LUT3
    generic map(
      INIT => X"E8"
    )
    port map (
      I0 => SW_1_IBUF_19,
      I1 => SW_5_IBUF_15,
      I2 => c0,
      O => c1
    );
  adder0_Cout1 : LUT3
    generic map(
      INIT => X"E8"
    )
    port map (
      I0 => SW_0_IBUF_20,
      I1 => SW_4_IBUF_16,
      I2 => carry_in_IBUF_1,
      O => c0
    );
  adder3_Mxor_S_Result1 : LUT3
    generic map(
      INIT => X"96"
    )
    port map (
      I0 => c2,
      I1 => SW_3_IBUF_17,
      I2 => SW_7_IBUF_13,
      O => s3
    );
  adder2_Mxor_S_Result1 : LUT3
    generic map(
      INIT => X"96"
    )
    port map (
      I0 => c1,
      I1 => SW_2_IBUF_18,
      I2 => SW_6_IBUF_14,
      O => s2
    );
  adder1_Mxor_S_Result1 : LUT3
    generic map(
      INIT => X"96"
    )
    port map (
      I0 => c0,
      I1 => SW_1_IBUF_19,
      I2 => SW_5_IBUF_15,
      O => s1
    );
  adder0_Mxor_S_Result1 : LUT3
    generic map(
      INIT => X"96"
    )
    port map (
      I0 => carry_in_IBUF_1,
      I1 => SW_0_IBUF_20,
      I2 => SW_4_IBUF_16,
      O => s0
    );
  display_driver0_Mrom_seg_out51 : LUT4
    generic map(
      INIT => X"454C"
    )
    port map (
      I0 => s3,
      I1 => s0,
      I2 => s1,
      I3 => s2,
      O => display_driver0_Mrom_seg_out4
    );
  display_driver0_Mrom_seg_out31 : LUT4
    generic map(
      INIT => X"80C2"
    )
    port map (
      I0 => s1,
      I1 => s3,
      I2 => s2,
      I3 => s0,
      O => display_driver0_Mrom_seg_out2
    );
  display_driver0_Mrom_seg_out71 : LUT4
    generic map(
      INIT => X"0941"
    )
    port map (
      I0 => s1,
      I1 => s2,
      I2 => s3,
      I3 => s0,
      O => display_driver0_Mrom_seg_out6
    );
  display_driver0_Mrom_seg_out61 : LUT4
    generic map(
      INIT => X"6032"
    )
    port map (
      I0 => s1,
      I1 => s3,
      I2 => s0,
      I3 => s2,
      O => display_driver0_Mrom_seg_out5
    );
  display_driver0_Mrom_seg_out21 : LUT4
    generic map(
      INIT => X"B860"
    )
    port map (
      I0 => s3,
      I1 => s0,
      I2 => s2,
      I3 => s1,
      O => display_driver0_Mrom_seg_out1
    );
  display_driver0_Mrom_seg_out41 : LUT4
    generic map(
      INIT => X"9086"
    )
    port map (
      I0 => s0,
      I1 => s2,
      I2 => s1,
      I3 => s3,
      O => display_driver0_Mrom_seg_out3
    );
  display_driver0_Mrom_seg_out11 : LUT4
    generic map(
      INIT => X"2812"
    )
    port map (
      I0 => s0,
      I1 => s1,
      I2 => s2,
      I3 => s3,
      O => display_driver0_Mrom_seg_out
    );
  carry_in_IBUF : IBUF
    port map (
      I => carry_in,
      O => carry_in_IBUF_1
    );
  SW_7_IBUF : IBUF
    port map (
      I => SW(7),
      O => SW_7_IBUF_13
    );
  SW_6_IBUF : IBUF
    port map (
      I => SW(6),
      O => SW_6_IBUF_14
    );
  SW_5_IBUF : IBUF
    port map (
      I => SW(5),
      O => SW_5_IBUF_15
    );
  SW_4_IBUF : IBUF
    port map (
      I => SW(4),
      O => SW_4_IBUF_16
    );
  SW_3_IBUF : IBUF
    port map (
      I => SW(3),
      O => SW_3_IBUF_17
    );
  SW_2_IBUF : IBUF
    port map (
      I => SW(2),
      O => SW_2_IBUF_18
    );
  SW_1_IBUF : IBUF
    port map (
      I => SW(1),
      O => SW_1_IBUF_19
    );
  SW_0_IBUF : IBUF
    port map (
      I => SW(0),
      O => SW_0_IBUF_20
    );
  an_0_OBUF : OBUF
    port map (
      I => an_0_OBUF_2,
      O => an(0)
    );
  an_1_OBUF : OBUF
    port map (
      I => an_1_OBUF_3,
      O => an(1)
    );
  an_2_OBUF : OBUF
    port map (
      I => an_2_OBUF_4,
      O => an(2)
    );
  an_3_OBUF : OBUF
    port map (
      I => an_3_OBUF_5,
      O => an(3)
    );
  seg_6_OBUF : OBUF
    port map (
      I => seg_6_OBUF_6,
      O => seg(6)
    );
  seg_5_OBUF : OBUF
    port map (
      I => seg_5_OBUF_7,
      O => seg(5)
    );
  seg_4_OBUF : OBUF
    port map (
      I => seg_4_OBUF_8,
      O => seg(4)
    );
  seg_3_OBUF : OBUF
    port map (
      I => seg_3_OBUF_9,
      O => seg(3)
    );
  seg_2_OBUF : OBUF
    port map (
      I => seg_2_OBUF_10,
      O => seg(2)
    );
  seg_1_OBUF : OBUF
    port map (
      I => seg_1_OBUF_11,
      O => seg(1)
    );
  seg_0_OBUF : OBUF
    port map (
      I => seg_0_OBUF_12,
      O => seg(0)
    );
  LEDdisplay1_cur_state_FFd2 : FDR
    generic map(
      INIT => '0'
    )
    port map (
      C => LEDdisplay1_Counter_Signal(14),
      D => display_driver1_Mrom_seg_out6,
      R => LEDdisplay1_cur_state_FFd1_21,
      Q => LEDdisplay1_cur_state_FFd2_22
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_1_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(1),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_1_rt_23
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_2_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(2),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_2_rt_24
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_3_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(3),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_3_rt_25
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_4_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(4),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_4_rt_26
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_5_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(5),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_5_rt_27
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_6_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(6),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_6_rt_28
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_7_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(7),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_7_rt_29
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_8_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(8),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_8_rt_30
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_9_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(9),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_9_rt_31
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_10_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(10),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_10_rt_32
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_11_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(11),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_11_rt_33
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_12_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(12),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_12_rt_34
    );
  LEDdisplay1_Mcount_Counter_Signal_cy_13_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(13),
      O => LEDdisplay1_Mcount_Counter_Signal_cy_13_rt_35
    );
  LEDdisplay1_Mcount_Counter_Signal_xor_14_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => LEDdisplay1_Counter_Signal(14),
      O => LEDdisplay1_Mcount_Counter_Signal_xor_14_rt_36
    );
  LEDdisplay1_dispMUX00_dispMUX501 : LUT3
    generic map(
      INIT => X"E8"
    )
    port map (
      I0 => SW_3_IBUF_17,
      I1 => SW_7_IBUF_13,
      I2 => c2,
      O => N39
    );
  LEDdisplay1_dispMUX00_dispMUX401 : LUT3
    generic map(
      INIT => X"E8"
    )
    port map (
      I0 => SW_3_IBUF_17,
      I1 => SW_7_IBUF_13,
      I2 => c2,
      O => N40
    );
  LEDdisplay1_dispMUX00_dispMUX301 : LUT3
    generic map(
      INIT => X"E8"
    )
    port map (
      I0 => SW_3_IBUF_17,
      I1 => SW_7_IBUF_13,
      I2 => c2,
      O => N41
    );
  clk_BUFGP : BUFGP
    port map (
      I => clk,
      O => clk_BUFGP_0
    );
  LEDdisplay1_Mcount_Counter_Signal_lut_0_INV_0 : INV
    port map (
      I => LEDdisplay1_Counter_Signal(0),
      O => Result(0)
    );

end Structure;

