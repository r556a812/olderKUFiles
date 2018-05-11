library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity masterSlave is
	Port (
		Clk, D : IN STD_LOGIC;
		Q      : OUT STD_LOGIC
	);
end masterSlave;

architecture Behavioral of masterSlave is

component DFlipFlop is
	Port (
		Clk, D : IN STD_LOGIC;
		Q      : OUT STD_LOGIC
	);
end component DFlipFlop;

signal Q_m: std_logic;

begin

master: DFlipFlop port map (Clk => Clk, D => D, Q => Q_m);
slave: DFlipFlop port map (Clk => NOT Clk, D => Q_m, Q => Q);

end Behavioral;