--------------------------------------------------------------------------------
-- Copyright (c) 1995-2007 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: J.36
--  \   \         Application: netgen
--  /   /         Filename: toplevel_synthesis.vhd
-- /___/   /\     Timestamp: Wed Apr 22 10:53:43 2015
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -ar Structure -tm toplevel -w -dir netgen/synthesis -ofmt vhdl -sim toplevel.ngc toplevel_synthesis.vhd 
-- Device	: xc3s500e-4-fg320
-- Input file	: toplevel.ngc
-- Output file	: \\fileserver.eecs.ku.edu\raviles\Lab12\netgen\synthesis\toplevel_synthesis.vhd
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
    anodes : out STD_LOGIC_VECTOR ( 3 downto 0 ); 
    segments : out STD_LOGIC_VECTOR ( 6 downto 0 ) 
  );
end toplevel;

architecture Structure of toplevel is
  signal clk_BUFGP_0 : STD_LOGIC; 
  signal anodes_3_OBUF_1 : STD_LOGIC; 
  signal anodes_2_OBUF_2 : STD_LOGIC; 
  signal anodes_1_OBUF_3 : STD_LOGIC; 
  signal anodes_0_OBUF_4 : STD_LOGIC; 
  signal segments_6_OBUF_5 : STD_LOGIC; 
  signal segments_5_OBUF_6 : STD_LOGIC; 
  signal segments_4_OBUF_7 : STD_LOGIC; 
  signal segments_3_OBUF_8 : STD_LOGIC; 
  signal segments_2_OBUF_9 : STD_LOGIC; 
  signal segments_1_OBUF_10 : STD_LOGIC; 
  signal segments_0_OBUF_11 : STD_LOGIC; 
  signal sig_segments1_6_Q : STD_LOGIC; 
  signal sig_segments1_4_Q : STD_LOGIC; 
  signal sig_segments1_3_Q : STD_LOGIC; 
  signal sig_segments1_1_Q : STD_LOGIC; 
  signal sig_segments1_0_Q : STD_LOGIC; 
  signal sig_segments2_6_Q : STD_LOGIC; 
  signal sig_segments2_4_Q : STD_LOGIC; 
  signal sig_segments2_3_Q : STD_LOGIC; 
  signal sig_segments2_1_Q : STD_LOGIC; 
  signal sig_segments2_0_Q : STD_LOGIC; 
  signal sig_segments3_6_Q : STD_LOGIC; 
  signal sig_segments3_4_Q : STD_LOGIC; 
  signal sig_segments3_3_Q : STD_LOGIC; 
  signal sig_segments3_1_Q : STD_LOGIC; 
  signal sig_segments3_0_Q : STD_LOGIC; 
  signal sig_segments4_6_Q : STD_LOGIC; 
  signal sig_segments4_4_Q : STD_LOGIC; 
  signal sig_segments4_3_Q : STD_LOGIC; 
  signal sig_segments4_1_Q : STD_LOGIC; 
  signal sig_segments4_0_Q : STD_LOGIC; 
  signal N0 : STD_LOGIC; 
  signal N1 : STD_LOGIC; 
  signal LEDdisplay1_cur_state_FFd1_12 : STD_LOGIC; 
  signal LEDdisplay1_cur_state_FFd2_13 : STD_LOGIC; 
  signal Result_1_1 : STD_LOGIC; 
  signal Result_2_1 : STD_LOGIC; 
  signal Result_3_1 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_1_rt_14 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_2_rt_15 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_3_rt_16 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_4_rt_17 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_5_rt_18 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_6_rt_19 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_7_rt_20 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_8_rt_21 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_9_rt_22 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_10_rt_23 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_11_rt_24 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_12_rt_25 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_13_rt_26 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_14_rt_27 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_15_rt_28 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_16_rt_29 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_17_rt_30 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_18_rt_31 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_19_rt_32 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_20_rt_33 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_21_rt_34 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_22_rt_35 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_cy_23_rt_36 : STD_LOGIC; 
  signal clock_divider_1_Mcount_count_xor_24_rt_37 : STD_LOGIC; 
  signal N42 : STD_LOGIC; 
  signal N43 : STD_LOGIC; 
  signal N44 : STD_LOGIC; 
  signal N45 : STD_LOGIC; 
  signal N46 : STD_LOGIC; 
  signal N47 : STD_LOGIC; 
  signal N48 : STD_LOGIC; 
  signal N49 : STD_LOGIC; 
  signal clock_divider_1_count : STD_LOGIC_VECTOR ( 24 downto 0 ); 
  signal counter1_counter_signal : STD_LOGIC_VECTOR ( 3 downto 0 ); 
  signal LEDdisplay1_control : STD_LOGIC_VECTOR ( 0 downto 0 ); 
  signal Result : STD_LOGIC_VECTOR ( 24 downto 0 ); 
  signal clock_divider_1_Mcount_count_cy : STD_LOGIC_VECTOR ( 23 downto 0 ); 
  signal LEDdisplay1_dispMUX00_seg1 : STD_LOGIC_VECTOR ( 6 downto 0 ); 
  signal LEDdisplay1_dispMUX00_seg0 : STD_LOGIC_VECTOR ( 6 downto 0 ); 
begin
  XST_VCC : VCC
    port map (
      P => N0
    );
  XST_GND : GND
    port map (
      G => N1
    );
  LEDdisplay1_cur_state_FFd1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clock_divider_1_count(14),
      D => LEDdisplay1_cur_state_FFd2_13,
      Q => LEDdisplay1_cur_state_FFd1_12
    );
  clock_divider_1_count_0 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(0),
      Q => clock_divider_1_count(0)
    );
  clock_divider_1_count_1 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(1),
      Q => clock_divider_1_count(1)
    );
  clock_divider_1_count_2 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(2),
      Q => clock_divider_1_count(2)
    );
  clock_divider_1_count_3 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(3),
      Q => clock_divider_1_count(3)
    );
  clock_divider_1_count_4 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(4),
      Q => clock_divider_1_count(4)
    );
  clock_divider_1_count_5 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(5),
      Q => clock_divider_1_count(5)
    );
  clock_divider_1_count_6 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(6),
      Q => clock_divider_1_count(6)
    );
  clock_divider_1_count_7 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(7),
      Q => clock_divider_1_count(7)
    );
  clock_divider_1_count_8 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(8),
      Q => clock_divider_1_count(8)
    );
  clock_divider_1_count_9 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(9),
      Q => clock_divider_1_count(9)
    );
  clock_divider_1_count_10 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(10),
      Q => clock_divider_1_count(10)
    );
  clock_divider_1_count_11 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(11),
      Q => clock_divider_1_count(11)
    );
  clock_divider_1_count_12 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(12),
      Q => clock_divider_1_count(12)
    );
  clock_divider_1_count_13 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(13),
      Q => clock_divider_1_count(13)
    );
  clock_divider_1_count_14 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(14),
      Q => clock_divider_1_count(14)
    );
  clock_divider_1_count_15 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(15),
      Q => clock_divider_1_count(15)
    );
  clock_divider_1_count_16 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(16),
      Q => clock_divider_1_count(16)
    );
  clock_divider_1_count_17 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(17),
      Q => clock_divider_1_count(17)
    );
  clock_divider_1_count_18 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(18),
      Q => clock_divider_1_count(18)
    );
  clock_divider_1_count_19 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(19),
      Q => clock_divider_1_count(19)
    );
  clock_divider_1_count_20 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(20),
      Q => clock_divider_1_count(20)
    );
  clock_divider_1_count_21 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(21),
      Q => clock_divider_1_count(21)
    );
  clock_divider_1_count_22 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(22),
      Q => clock_divider_1_count(22)
    );
  clock_divider_1_count_23 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(23),
      Q => clock_divider_1_count(23)
    );
  clock_divider_1_count_24 : FD
    port map (
      C => clk_BUFGP_0,
      D => Result(24),
      Q => clock_divider_1_count(24)
    );
  counter1_counter_signal_1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clock_divider_1_count(24),
      D => Result_1_1,
      Q => counter1_counter_signal(1)
    );
  counter1_counter_signal_2 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clock_divider_1_count(24),
      D => Result_2_1,
      Q => counter1_counter_signal(2)
    );
  counter1_counter_signal_3 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clock_divider_1_count(24),
      D => Result_3_1,
      Q => counter1_counter_signal(3)
    );
  clock_divider_1_Mcount_count_cy_0_Q : MUXCY
    port map (
      CI => N1,
      DI => N0,
      S => Result(0),
      O => clock_divider_1_Mcount_count_cy(0)
    );
  clock_divider_1_Mcount_count_cy_1_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(0),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_1_rt_14,
      O => clock_divider_1_Mcount_count_cy(1)
    );
  clock_divider_1_Mcount_count_xor_1_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(0),
      LI => clock_divider_1_Mcount_count_cy_1_rt_14,
      O => Result(1)
    );
  clock_divider_1_Mcount_count_cy_2_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(1),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_2_rt_15,
      O => clock_divider_1_Mcount_count_cy(2)
    );
  clock_divider_1_Mcount_count_xor_2_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(1),
      LI => clock_divider_1_Mcount_count_cy_2_rt_15,
      O => Result(2)
    );
  clock_divider_1_Mcount_count_cy_3_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(2),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_3_rt_16,
      O => clock_divider_1_Mcount_count_cy(3)
    );
  clock_divider_1_Mcount_count_xor_3_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(2),
      LI => clock_divider_1_Mcount_count_cy_3_rt_16,
      O => Result(3)
    );
  clock_divider_1_Mcount_count_cy_4_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(3),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_4_rt_17,
      O => clock_divider_1_Mcount_count_cy(4)
    );
  clock_divider_1_Mcount_count_xor_4_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(3),
      LI => clock_divider_1_Mcount_count_cy_4_rt_17,
      O => Result(4)
    );
  clock_divider_1_Mcount_count_cy_5_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(4),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_5_rt_18,
      O => clock_divider_1_Mcount_count_cy(5)
    );
  clock_divider_1_Mcount_count_xor_5_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(4),
      LI => clock_divider_1_Mcount_count_cy_5_rt_18,
      O => Result(5)
    );
  clock_divider_1_Mcount_count_cy_6_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(5),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_6_rt_19,
      O => clock_divider_1_Mcount_count_cy(6)
    );
  clock_divider_1_Mcount_count_xor_6_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(5),
      LI => clock_divider_1_Mcount_count_cy_6_rt_19,
      O => Result(6)
    );
  clock_divider_1_Mcount_count_cy_7_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(6),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_7_rt_20,
      O => clock_divider_1_Mcount_count_cy(7)
    );
  clock_divider_1_Mcount_count_xor_7_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(6),
      LI => clock_divider_1_Mcount_count_cy_7_rt_20,
      O => Result(7)
    );
  clock_divider_1_Mcount_count_cy_8_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(7),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_8_rt_21,
      O => clock_divider_1_Mcount_count_cy(8)
    );
  clock_divider_1_Mcount_count_xor_8_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(7),
      LI => clock_divider_1_Mcount_count_cy_8_rt_21,
      O => Result(8)
    );
  clock_divider_1_Mcount_count_cy_9_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(8),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_9_rt_22,
      O => clock_divider_1_Mcount_count_cy(9)
    );
  clock_divider_1_Mcount_count_xor_9_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(8),
      LI => clock_divider_1_Mcount_count_cy_9_rt_22,
      O => Result(9)
    );
  clock_divider_1_Mcount_count_cy_10_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(9),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_10_rt_23,
      O => clock_divider_1_Mcount_count_cy(10)
    );
  clock_divider_1_Mcount_count_xor_10_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(9),
      LI => clock_divider_1_Mcount_count_cy_10_rt_23,
      O => Result(10)
    );
  clock_divider_1_Mcount_count_cy_11_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(10),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_11_rt_24,
      O => clock_divider_1_Mcount_count_cy(11)
    );
  clock_divider_1_Mcount_count_xor_11_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(10),
      LI => clock_divider_1_Mcount_count_cy_11_rt_24,
      O => Result(11)
    );
  clock_divider_1_Mcount_count_cy_12_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(11),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_12_rt_25,
      O => clock_divider_1_Mcount_count_cy(12)
    );
  clock_divider_1_Mcount_count_xor_12_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(11),
      LI => clock_divider_1_Mcount_count_cy_12_rt_25,
      O => Result(12)
    );
  clock_divider_1_Mcount_count_cy_13_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(12),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_13_rt_26,
      O => clock_divider_1_Mcount_count_cy(13)
    );
  clock_divider_1_Mcount_count_xor_13_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(12),
      LI => clock_divider_1_Mcount_count_cy_13_rt_26,
      O => Result(13)
    );
  clock_divider_1_Mcount_count_cy_14_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(13),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_14_rt_27,
      O => clock_divider_1_Mcount_count_cy(14)
    );
  clock_divider_1_Mcount_count_xor_14_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(13),
      LI => clock_divider_1_Mcount_count_cy_14_rt_27,
      O => Result(14)
    );
  clock_divider_1_Mcount_count_cy_15_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(14),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_15_rt_28,
      O => clock_divider_1_Mcount_count_cy(15)
    );
  clock_divider_1_Mcount_count_xor_15_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(14),
      LI => clock_divider_1_Mcount_count_cy_15_rt_28,
      O => Result(15)
    );
  clock_divider_1_Mcount_count_cy_16_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(15),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_16_rt_29,
      O => clock_divider_1_Mcount_count_cy(16)
    );
  clock_divider_1_Mcount_count_xor_16_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(15),
      LI => clock_divider_1_Mcount_count_cy_16_rt_29,
      O => Result(16)
    );
  clock_divider_1_Mcount_count_cy_17_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(16),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_17_rt_30,
      O => clock_divider_1_Mcount_count_cy(17)
    );
  clock_divider_1_Mcount_count_xor_17_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(16),
      LI => clock_divider_1_Mcount_count_cy_17_rt_30,
      O => Result(17)
    );
  clock_divider_1_Mcount_count_cy_18_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(17),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_18_rt_31,
      O => clock_divider_1_Mcount_count_cy(18)
    );
  clock_divider_1_Mcount_count_xor_18_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(17),
      LI => clock_divider_1_Mcount_count_cy_18_rt_31,
      O => Result(18)
    );
  clock_divider_1_Mcount_count_cy_19_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(18),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_19_rt_32,
      O => clock_divider_1_Mcount_count_cy(19)
    );
  clock_divider_1_Mcount_count_xor_19_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(18),
      LI => clock_divider_1_Mcount_count_cy_19_rt_32,
      O => Result(19)
    );
  clock_divider_1_Mcount_count_cy_20_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(19),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_20_rt_33,
      O => clock_divider_1_Mcount_count_cy(20)
    );
  clock_divider_1_Mcount_count_xor_20_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(19),
      LI => clock_divider_1_Mcount_count_cy_20_rt_33,
      O => Result(20)
    );
  clock_divider_1_Mcount_count_cy_21_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(20),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_21_rt_34,
      O => clock_divider_1_Mcount_count_cy(21)
    );
  clock_divider_1_Mcount_count_xor_21_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(20),
      LI => clock_divider_1_Mcount_count_cy_21_rt_34,
      O => Result(21)
    );
  clock_divider_1_Mcount_count_cy_22_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(21),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_22_rt_35,
      O => clock_divider_1_Mcount_count_cy(22)
    );
  clock_divider_1_Mcount_count_xor_22_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(21),
      LI => clock_divider_1_Mcount_count_cy_22_rt_35,
      O => Result(22)
    );
  clock_divider_1_Mcount_count_cy_23_Q : MUXCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(22),
      DI => N1,
      S => clock_divider_1_Mcount_count_cy_23_rt_36,
      O => clock_divider_1_Mcount_count_cy(23)
    );
  clock_divider_1_Mcount_count_xor_23_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(22),
      LI => clock_divider_1_Mcount_count_cy_23_rt_36,
      O => Result(23)
    );
  clock_divider_1_Mcount_count_xor_24_Q : XORCY
    port map (
      CI => clock_divider_1_Mcount_count_cy(23),
      LI => clock_divider_1_Mcount_count_xor_24_rt_37,
      O => Result(24)
    );
  LEDdisplay1_dispMUX00_dispMUX62 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(6),
      I1 => LEDdisplay1_dispMUX00_seg1(6),
      S => LEDdisplay1_cur_state_FFd1_12,
      O => segments_6_OBUF_5
    );
  LEDdisplay1_dispMUX00_dispMUX61 : MUXF5
    port map (
      I0 => sig_segments3_6_Q,
      I1 => sig_segments4_6_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(6)
    );
  LEDdisplay1_dispMUX00_dispMUX60 : MUXF5
    port map (
      I0 => sig_segments1_6_Q,
      I1 => sig_segments2_6_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(6)
    );
  LEDdisplay1_dispMUX00_dispMUX52 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(5),
      I1 => LEDdisplay1_dispMUX00_seg1(5),
      S => LEDdisplay1_cur_state_FFd1_12,
      O => segments_5_OBUF_6
    );
  LEDdisplay1_dispMUX00_dispMUX51 : MUXF5
    port map (
      I0 => N42,
      I1 => N43,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(5)
    );
  LEDdisplay1_dispMUX00_dispMUX50 : MUXF5
    port map (
      I0 => N44,
      I1 => N45,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(5)
    );
  LEDdisplay1_dispMUX00_dispMUX42 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(4),
      I1 => LEDdisplay1_dispMUX00_seg1(4),
      S => LEDdisplay1_cur_state_FFd1_12,
      O => segments_4_OBUF_7
    );
  LEDdisplay1_dispMUX00_dispMUX41 : MUXF5
    port map (
      I0 => sig_segments3_4_Q,
      I1 => sig_segments4_4_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(4)
    );
  LEDdisplay1_dispMUX00_dispMUX40 : MUXF5
    port map (
      I0 => sig_segments1_4_Q,
      I1 => sig_segments2_4_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(4)
    );
  LEDdisplay1_dispMUX00_dispMUX32 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(3),
      I1 => LEDdisplay1_dispMUX00_seg1(3),
      S => LEDdisplay1_cur_state_FFd1_12,
      O => segments_3_OBUF_8
    );
  LEDdisplay1_dispMUX00_dispMUX31 : MUXF5
    port map (
      I0 => sig_segments3_3_Q,
      I1 => sig_segments4_3_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(3)
    );
  LEDdisplay1_dispMUX00_dispMUX30 : MUXF5
    port map (
      I0 => sig_segments1_3_Q,
      I1 => sig_segments2_3_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(3)
    );
  LEDdisplay1_dispMUX00_dispMUX22 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(2),
      I1 => LEDdisplay1_dispMUX00_seg1(2),
      S => LEDdisplay1_cur_state_FFd1_12,
      O => segments_2_OBUF_9
    );
  LEDdisplay1_dispMUX00_dispMUX21 : MUXF5
    port map (
      I0 => N46,
      I1 => N47,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(2)
    );
  LEDdisplay1_dispMUX00_dispMUX20 : MUXF5
    port map (
      I0 => N48,
      I1 => N49,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(2)
    );
  LEDdisplay1_dispMUX00_dispMUX12 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(1),
      I1 => LEDdisplay1_dispMUX00_seg1(1),
      S => LEDdisplay1_cur_state_FFd1_12,
      O => segments_1_OBUF_10
    );
  LEDdisplay1_dispMUX00_dispMUX11 : MUXF5
    port map (
      I0 => sig_segments3_1_Q,
      I1 => sig_segments4_1_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(1)
    );
  LEDdisplay1_dispMUX00_dispMUX10 : MUXF5
    port map (
      I0 => sig_segments1_1_Q,
      I1 => sig_segments2_1_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(1)
    );
  LEDdisplay1_dispMUX00_dispMUX02 : MUXF6
    port map (
      I0 => LEDdisplay1_dispMUX00_seg0(0),
      I1 => LEDdisplay1_dispMUX00_seg1(0),
      S => LEDdisplay1_cur_state_FFd1_12,
      O => segments_0_OBUF_11
    );
  LEDdisplay1_dispMUX00_dispMUX01 : MUXF5
    port map (
      I0 => sig_segments3_0_Q,
      I1 => sig_segments4_0_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg1(0)
    );
  LEDdisplay1_dispMUX00_dispMUX00 : MUXF5
    port map (
      I0 => sig_segments1_0_Q,
      I1 => sig_segments2_0_Q,
      S => LEDdisplay1_control(0),
      O => LEDdisplay1_dispMUX00_seg0(0)
    );
  display_driver_4_seg_out_3_1 : LUT2
    generic map(
      INIT => X"D"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(3),
      O => sig_segments4_3_Q
    );
  LEDdisplay1_cur_state_Out51 : LUT2
    generic map(
      INIT => X"E"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd1_12,
      I1 => LEDdisplay1_cur_state_FFd2_13,
      O => anodes_0_OBUF_4
    );
  LEDdisplay1_cur_state_Out41 : LUT2
    generic map(
      INIT => X"D"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd2_13,
      I1 => LEDdisplay1_cur_state_FFd1_12,
      O => anodes_1_OBUF_3
    );
  LEDdisplay1_cur_state_Out31 : LUT2
    generic map(
      INIT => X"7"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd2_13,
      I1 => LEDdisplay1_cur_state_FFd1_12,
      O => anodes_2_OBUF_2
    );
  LEDdisplay1_cur_state_Out21 : LUT2
    generic map(
      INIT => X"D"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd1_12,
      I1 => LEDdisplay1_cur_state_FFd2_13,
      O => anodes_3_OBUF_1
    );
  LEDdisplay1_cur_state_Out11 : LUT2
    generic map(
      INIT => X"6"
    )
    port map (
      I0 => LEDdisplay1_cur_state_FFd2_13,
      I1 => LEDdisplay1_cur_state_FFd1_12,
      O => LEDdisplay1_control(0)
    );
  display_driver_4_seg_out_1_1 : LUT3
    generic map(
      INIT => X"F7"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(3),
      O => sig_segments4_1_Q
    );
  display_driver_3_seg_out_6_1 : LUT3
    generic map(
      INIT => X"FD"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(2),
      I2 => counter1_counter_signal(3),
      O => sig_segments3_6_Q
    );
  display_driver_3_seg_out_1_1 : LUT3
    generic map(
      INIT => X"FD"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(3),
      O => sig_segments3_1_Q
    );
  display_driver_2_seg_out_1_1 : LUT3
    generic map(
      INIT => X"FD"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(3),
      I2 => counter1_counter_signal(1),
      O => sig_segments2_1_Q
    );
  display_driver_1_seg_out_6_1 : LUT3
    generic map(
      INIT => X"FE"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(3),
      I2 => counter1_counter_signal(1),
      O => sig_segments1_6_Q
    );
  display_driver_1_seg_out_1_1 : LUT3
    generic map(
      INIT => X"FE"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(3),
      I2 => counter1_counter_signal(1),
      O => sig_segments1_1_Q
    );
  display_driver_2_seg_out_3_1 : LUT3
    generic map(
      INIT => X"F9"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(2),
      I2 => counter1_counter_signal(3),
      O => sig_segments2_3_Q
    );
  display_driver_4_seg_out_4_1 : LUT4
    generic map(
      INIT => X"FF15"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(1),
      I3 => counter1_counter_signal(3),
      O => sig_segments4_4_Q
    );
  display_driver_1_seg_out_4_1 : LUT4
    generic map(
      INIT => X"FFA8"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(1),
      I3 => counter1_counter_signal(3),
      O => sig_segments1_4_Q
    );
  display_driver_3_seg_out_4_1 : LUT4
    generic map(
      INIT => X"FF83"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(2),
      I2 => counter1_counter_signal(1),
      I3 => counter1_counter_signal(3),
      O => sig_segments3_4_Q
    );
  display_driver_3_seg_out_0_1 : LUT4
    generic map(
      INIT => X"FF9F"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(1),
      I3 => counter1_counter_signal(3),
      O => sig_segments3_0_Q
    );
  display_driver_2_seg_out_6_1 : LUT4
    generic map(
      INIT => X"FFF9"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(1),
      I2 => counter1_counter_signal(3),
      I3 => counter1_counter_signal(2),
      O => sig_segments2_6_Q
    );
  display_driver_2_seg_out_4_1 : LUT4
    generic map(
      INIT => X"F8F9"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(2),
      I2 => counter1_counter_signal(3),
      I3 => counter1_counter_signal(0),
      O => sig_segments2_4_Q
    );
  display_driver_1_seg_out_0_1 : LUT4
    generic map(
      INIT => X"FFF9"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(1),
      I3 => counter1_counter_signal(3),
      O => sig_segments1_0_Q
    );
  display_driver_2_seg_out_0_1 : LUT4
    generic map(
      INIT => X"FFDB"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(1),
      I2 => counter1_counter_signal(0),
      I3 => counter1_counter_signal(3),
      O => sig_segments2_0_Q
    );
  counter1_Mcount_counter_signal_xor_1_11 : LUT2
    generic map(
      INIT => X"6"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(0),
      O => Result_1_1
    );
  counter1_Mcount_counter_signal_xor_2_11 : LUT3
    generic map(
      INIT => X"6C"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(2),
      I2 => counter1_counter_signal(1),
      O => Result_2_1
    );
  counter1_Mcount_counter_signal_xor_3_11 : LUT4
    generic map(
      INIT => X"6CCC"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(3),
      I2 => counter1_counter_signal(1),
      I3 => counter1_counter_signal(2),
      O => Result_3_1
    );
  anodes_3_OBUF : OBUF
    port map (
      I => anodes_3_OBUF_1,
      O => anodes(3)
    );
  anodes_2_OBUF : OBUF
    port map (
      I => anodes_2_OBUF_2,
      O => anodes(2)
    );
  anodes_1_OBUF : OBUF
    port map (
      I => anodes_1_OBUF_3,
      O => anodes(1)
    );
  anodes_0_OBUF : OBUF
    port map (
      I => anodes_0_OBUF_4,
      O => anodes(0)
    );
  segments_6_OBUF : OBUF
    port map (
      I => segments_6_OBUF_5,
      O => segments(6)
    );
  segments_5_OBUF : OBUF
    port map (
      I => segments_5_OBUF_6,
      O => segments(5)
    );
  segments_4_OBUF : OBUF
    port map (
      I => segments_4_OBUF_7,
      O => segments(4)
    );
  segments_3_OBUF : OBUF
    port map (
      I => segments_3_OBUF_8,
      O => segments(3)
    );
  segments_2_OBUF : OBUF
    port map (
      I => segments_2_OBUF_9,
      O => segments(2)
    );
  segments_1_OBUF : OBUF
    port map (
      I => segments_1_OBUF_10,
      O => segments(1)
    );
  segments_0_OBUF : OBUF
    port map (
      I => segments_0_OBUF_11,
      O => segments(0)
    );
  LEDdisplay1_cur_state_FFd2 : FDR
    generic map(
      INIT => '0'
    )
    port map (
      C => clock_divider_1_count(14),
      D => N0,
      R => LEDdisplay1_cur_state_FFd1_12,
      Q => LEDdisplay1_cur_state_FFd2_13
    );
  counter1_counter_signal_0 : FDR
    generic map(
      INIT => '0'
    )
    port map (
      C => clock_divider_1_count(24),
      D => N0,
      R => counter1_counter_signal(0),
      Q => counter1_counter_signal(0)
    );
  clock_divider_1_Mcount_count_cy_1_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(1),
      O => clock_divider_1_Mcount_count_cy_1_rt_14
    );
  clock_divider_1_Mcount_count_cy_2_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(2),
      O => clock_divider_1_Mcount_count_cy_2_rt_15
    );
  clock_divider_1_Mcount_count_cy_3_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(3),
      O => clock_divider_1_Mcount_count_cy_3_rt_16
    );
  clock_divider_1_Mcount_count_cy_4_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(4),
      O => clock_divider_1_Mcount_count_cy_4_rt_17
    );
  clock_divider_1_Mcount_count_cy_5_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(5),
      O => clock_divider_1_Mcount_count_cy_5_rt_18
    );
  clock_divider_1_Mcount_count_cy_6_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(6),
      O => clock_divider_1_Mcount_count_cy_6_rt_19
    );
  clock_divider_1_Mcount_count_cy_7_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(7),
      O => clock_divider_1_Mcount_count_cy_7_rt_20
    );
  clock_divider_1_Mcount_count_cy_8_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(8),
      O => clock_divider_1_Mcount_count_cy_8_rt_21
    );
  clock_divider_1_Mcount_count_cy_9_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(9),
      O => clock_divider_1_Mcount_count_cy_9_rt_22
    );
  clock_divider_1_Mcount_count_cy_10_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(10),
      O => clock_divider_1_Mcount_count_cy_10_rt_23
    );
  clock_divider_1_Mcount_count_cy_11_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(11),
      O => clock_divider_1_Mcount_count_cy_11_rt_24
    );
  clock_divider_1_Mcount_count_cy_12_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(12),
      O => clock_divider_1_Mcount_count_cy_12_rt_25
    );
  clock_divider_1_Mcount_count_cy_13_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(13),
      O => clock_divider_1_Mcount_count_cy_13_rt_26
    );
  clock_divider_1_Mcount_count_cy_14_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(14),
      O => clock_divider_1_Mcount_count_cy_14_rt_27
    );
  clock_divider_1_Mcount_count_cy_15_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(15),
      O => clock_divider_1_Mcount_count_cy_15_rt_28
    );
  clock_divider_1_Mcount_count_cy_16_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(16),
      O => clock_divider_1_Mcount_count_cy_16_rt_29
    );
  clock_divider_1_Mcount_count_cy_17_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(17),
      O => clock_divider_1_Mcount_count_cy_17_rt_30
    );
  clock_divider_1_Mcount_count_cy_18_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(18),
      O => clock_divider_1_Mcount_count_cy_18_rt_31
    );
  clock_divider_1_Mcount_count_cy_19_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(19),
      O => clock_divider_1_Mcount_count_cy_19_rt_32
    );
  clock_divider_1_Mcount_count_cy_20_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(20),
      O => clock_divider_1_Mcount_count_cy_20_rt_33
    );
  clock_divider_1_Mcount_count_cy_21_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(21),
      O => clock_divider_1_Mcount_count_cy_21_rt_34
    );
  clock_divider_1_Mcount_count_cy_22_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(22),
      O => clock_divider_1_Mcount_count_cy_22_rt_35
    );
  clock_divider_1_Mcount_count_cy_23_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(23),
      O => clock_divider_1_Mcount_count_cy_23_rt_36
    );
  clock_divider_1_Mcount_count_xor_24_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => clock_divider_1_count(24),
      O => clock_divider_1_Mcount_count_xor_24_rt_37
    );
  LEDdisplay1_dispMUX00_dispMUX511 : LUT4
    generic map(
      INIT => X"FF83"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(2),
      I2 => counter1_counter_signal(1),
      I3 => counter1_counter_signal(3),
      O => N42
    );
  LEDdisplay1_dispMUX00_dispMUX512 : LUT4
    generic map(
      INIT => X"FF15"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(1),
      I3 => counter1_counter_signal(3),
      O => N43
    );
  LEDdisplay1_dispMUX00_dispMUX501 : LUT4
    generic map(
      INIT => X"FFA8"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(1),
      I3 => counter1_counter_signal(3),
      O => N44
    );
  LEDdisplay1_dispMUX00_dispMUX502 : LUT4
    generic map(
      INIT => X"F8F9"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(2),
      I2 => counter1_counter_signal(3),
      I3 => counter1_counter_signal(0),
      O => N45
    );
  LEDdisplay1_dispMUX00_dispMUX211 : LUT3
    generic map(
      INIT => X"FD"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(3),
      O => N46
    );
  LEDdisplay1_dispMUX00_dispMUX212 : LUT3
    generic map(
      INIT => X"F7"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(3),
      O => N47
    );
  LEDdisplay1_dispMUX00_dispMUX201 : LUT3
    generic map(
      INIT => X"FE"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(3),
      I2 => counter1_counter_signal(1),
      O => N48
    );
  LEDdisplay1_dispMUX00_dispMUX202 : LUT3
    generic map(
      INIT => X"FD"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(3),
      I2 => counter1_counter_signal(1),
      O => N49
    );
  display_driver_4_seg_out_6_1 : LUT4
    generic map(
      INIT => X"FFDB"
    )
    port map (
      I0 => counter1_counter_signal(1),
      I1 => counter1_counter_signal(2),
      I2 => counter1_counter_signal(0),
      I3 => counter1_counter_signal(3),
      O => sig_segments4_6_Q
    );
  display_driver_3_seg_out_3_1 : LUT4
    generic map(
      INIT => X"F9F5"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(0),
      I2 => counter1_counter_signal(3),
      I3 => counter1_counter_signal(1),
      O => sig_segments3_3_Q
    );
  display_driver_1_seg_out_3_1 : LUT4
    generic map(
      INIT => X"FFA9"
    )
    port map (
      I0 => counter1_counter_signal(2),
      I1 => counter1_counter_signal(1),
      I2 => counter1_counter_signal(0),
      I3 => counter1_counter_signal(3),
      O => sig_segments1_3_Q
    );
  display_driver_4_seg_out_0_1 : LUT4
    generic map(
      INIT => X"F6FF"
    )
    port map (
      I0 => counter1_counter_signal(0),
      I1 => counter1_counter_signal(1),
      I2 => counter1_counter_signal(3),
      I3 => counter1_counter_signal(2),
      O => sig_segments4_0_Q
    );
  clk_BUFGP : BUFGP
    port map (
      I => clk,
      O => clk_BUFGP_0
    );
  clock_divider_1_Mcount_count_lut_0_INV_0 : INV
    port map (
      I => clock_divider_1_count(0),
      O => Result(0)
    );

end Structure;

