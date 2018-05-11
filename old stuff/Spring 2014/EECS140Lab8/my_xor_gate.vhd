----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:37:51 03/25/2015 
-- Design Name: 
-- Module Name:    my_xor_gate - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity my_xor_gate is
	PORT (
		A,B : IN STD_LOGIC;
		C	 : OUT STD_LOGIC);
end my_xor_gate;

architecture Behavioral of my_xor_gate is

begin
	C <= (A AND (NOT B)) OR ((NOT A) AND B);

end Behavioral;

