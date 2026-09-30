<#-- Polyman Generator Script Template (Freemarker format)

Syntax:
  > $         - next free test index
  > 5         - explicit index 5
  > {40-41}   - multi-output (one generator creates tests 40 and 41)
  <#-- @group name --> - assign group
  <#list 1..N as i> - loop
-->

<#-- @group samples -->
<#-- Manual tests configured in Config.json manualTests, not here -->

<#-- @group small -->
<#list 1..10 as i>
gen-random -n 100 -seed ${i} > $
</#list>

<#-- @group medium -->
<#list 1..15 as i>
gen-random -n 10000 -seed ${100 + i} > $
</#list>

<#-- @group large -->
gen-random -n 200000 -seed 1000 > $
gen-random -n 200000 -seed 1001 > $
gen-worst-case -n 200000 > $

<#-- @group edge -->
gen-edge -type min > $
gen-edge -type max > $

<#-- Multi-output example:
gen-multi 10 > {50-59}
-->
