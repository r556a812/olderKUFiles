library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity toplevel is
Port ( clk : in std_logic;
		 segments : out std_logic_vector (6 downto 0);
		 anodes :out std_logic_vector (3 downto 0));
end toplevel;

architecture Behavioral of toplevel is

component clock_divider is
	Port ( clk : in  STD_LOGIC;
			 message_clk : out STD_LOGIC
			 );
end component clock_divider;

component counter is
port ( clock : in std_logic;
		 enable : in std_logic;
		 load_n : in std_logic;
		 initial_value : in std_logic_vector (3 downto 0);
		 clear_n : in std_logic;
		 counter_output : out std_logic_vector (3 downto 0));
end component counter;

component display_driver1 is
    Port ( inputs : in  STD_LOGIC_VECTOR (3 downto 0);
           seg_out : out  STD_LOGIC_VECTOR (6 downto 0));
end component display_driver1;

component display_driver2 is
    Port ( inputs : in  STD_LOGIC_VECTOR (3 downto 0);
           seg_out : out  STD_LOGIC_VECTOR (6 downto 0));
end component display_driver2;

component display_driver3 is
    Port ( inputs : in  STD_LOGIC_VECTOR (3 downto 0);
           seg_out : out  STD_LOGIC_VECTOR (6 downto 0));
end component display_driver3;

component display_driver4 is
    Port ( inputs : in  STD_LOGIC_VECTOR (3 downto 0);
           seg_out : out  STD_LOGIC_VECTOR (6 downto 0));
end component display_driver4;


component LEDdisplay0 IS
	PORT (
		  clk					: IN  STD_LOGIC;
		  seg0,seg1,seg2,seg3		: IN  STD_LOGIC_VECTOR(6 downto 0);
        seg       		: OUT  STD_LOGIC_VECTOR(6  downto 0);
		  an					: OUT STD_LOGIC_VECTOR(3 downto 0));		  
END component LEDdisplay0;

signal m_clk: std_logic;
signal cnt_out: std_logic_vector (3 downto 0);
signal sig_segments1, sig_segments2, sig_segments3, sig_segments4: std_logic_vector (6 downto 0);

begin

counter1: counter port map (clock => m_clk, enable => '1', load_n => '1', initial_value => "0000", clear_n => '1', counter_output => cnt_out);
clock_divider_1: clock_divider port map (clk => clk, message_clk => m_clk);
display_driver_1: display_driver1 port map (inputs => cnt_out, seg_out => sig_segments1);
display_driver_2: display_driver2 port map (inputs => cnt_out, seg_out => sig_segments2);
display_driver_3: display_driver3 port map (inputs => cnt_out, seg_out => sig_segments3);
display_driver_4: display_driver4 port map (inputs => cnt_out, seg_out => sig_segments4);
LEDdisplay1: LEDdisplay0 port map (seg0 => sig_segments1, seg1 => sig_segments2, seg2 => sig_segments3, seg3 => sig_segments4, clk => clk, seg => segments, an => anodes);


end Behavioral;

