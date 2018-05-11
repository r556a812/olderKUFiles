library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity toplevel is
	Port ( switches : in  STD_LOGIC_VECTOR (7 downto 0);
          segments : out  STD_LOGIC_VECTOR (6 downto 0);
          anodes : out  STD_LOGIC_VECTOR (0 to 3);
          control : in  STD_LOGIC_VECTOR (1 downto 0);
          carry_in : in  STD_LOGIC;
          clk : in  STD_LOGIC
	);
end toplevel;

architecture Behavioral of toplevel is

component ANDer is
	Port (
		Input0 : in STD_LOGIC_VECTOR (3 downto 0);
		Input1 : in STD_LOGIC_VECTOR (3 downto 0);
		Output : out STD_LOGIC_VECTOR (3 downto 0)
	);
end component ANDer;

component ORer is
	Port (
		Input0 : in STD_LOGIC_VECTOR (3 downto 0);
		Input1 : in STD_LOGIC_VECTOR (3 downto 0);
		Output : out STD_LOGIC_VECTOR (3 downto 0)
	);
end component ORer;

component XORer is
	Port (
		Input0 : in STD_LOGIC_VECTOR (3 downto 0);
		Input1 : in STD_LOGIC_VECTOR (3 downto 0);
		Output : out STD_LOGIC_VECTOR (3 downto 0)
	);
end component XORer;
 
component ADDer is
	Port (
		Input0 : in STD_LOGIC_VECTOR (3 downto 0);
		Input1 : in STD_LOGIC_VECTOR (3 downto 0);
		Output : out STD_LOGIC_VECTOR (4 downto 0)
	);
end component ADDer;

component function_select is
	Port (
		Input0  : in  STD_LOGIC_VECTOR (3 downto 0);
		Input1  : in  STD_LOGIC_VECTOR (3 downto 0);
		Input2  : in  STD_LOGIC_VECTOR (3 downto 0);
		Input3  : in  STD_LOGIC_VECTOR (4 downto 0);
		control : in  STD_LOGIC_VECTOR (1 downto 0);
		Output  : out  STD_LOGIC_VECTOR (4 downto 0)
	);
end component function_select;

component display_driver is
	Port (
		inputs : in  STD_LOGIC_VECTOR (3 downto 0);
		seg_out : out  STD_LOGIC_VECTOR (6 downto 0)
	);
end component display_driver;
 
component LEDdisplay is
	PORT (
		clk                 : IN  STD_LOGIC;
		seg0,seg1,seg2,seg3 : IN  STD_LOGIC_VECTOR(6 downto 0);
		seg                 : OUT STD_LOGIC_VECTOR(6 downto 0);
		an                  : OUT STD_LOGIC_VECTOR(3 downto 0)
	);
end component LEDdisplay;

signal out_and, out_or, out_xor: std_logic_vector (3 downto 0);
signal out_adder, out_select: std_logic_vector (4 downto 0);
signal sig_segments1, sig_segments2: std_logic_vector (6 downto 0);
signal sig_segments3, sig_segments4 : std_logic_vector(6 downto 0):= "1111111";
signal sw1, sw2: std_logic_vector (3 downto 0);

begin

sw1 <= switches(3) & switches(2) & switches(1) & switches(0);
sw2 <= switches(7) & switches(6) & switches(5) & switches(4);

-- port mapping --
ANDer0: ANDer port map (Input0 => sw1, Input1 => sw2, Output => out_and);
ORer0: ORer port map (Input0 => sw1, Input1 => sw2, Output => out_or);
XORer0: XORer port map (Input0 => sw1, Input1 => sw2, Output => out_xor);
ADDer0: ADDer port map (Input0 => sw1, Input1 => sw2, Output => out_adder);
LEDdisplay0: LEDdisplay port map (clk=>clk, seg0=>sig_segments1, seg1=>sig_segments2, seg2=>sig_segments3, seg3=>sig_segments4, seg=>segments, an=>anodes);
function_select0: function_select port map (Input0 => out_and, Input1 => out_or, Input2 => out_xor, Input3 => out_adder, control => control, Output => out_select);
display_driver0: display_driver port map (inputs(0) => out_select(0), inputs(1) => out_select(1), inputs(2) => out_select(2), inputs(3) => out_select(3), seg_out=> sig_segments1);
display_driver1: display_driver port map (inputs(0)=>out_select(4) , inputs(1)=>'0', inputs(2)=>'0', inputs(3)=>'0', seg_out=> sig_segments2);

end Behavioral;