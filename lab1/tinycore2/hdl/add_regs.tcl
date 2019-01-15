# ADAPT command at the end of this file and type "source add_regs.tcl" at the
# ISS command prompt then click reconnect button and simulate as usual

# Adding registers to file output:

proc add_reg_fo { iss ofile {skiplist {}} } {
    set sl [$iss info storage]
    foreach s $sl {
	::tclutils::list2array $::iss::storinfo_keys $s sa
	if { $sa(is_physical) 
	     && ![string match "__*" $sa(storage_name)] 
	     && [string equal $sa(storage_type) "register"]
	     && [lsearch $skiplist $sa(storage_name)] < 0 } { 
	    for { set f 0 } { $f < $sa(nbr_addresses) } { incr f } {
		$iss fileoutput add $sa(storage_name) $f \
		    -field \
		    -file $ofile \
		    -print_mode when_changed \
		    -verbose true \
		    -format go_vhdl
	    }
	}
    }
}

# add '-radix hex' after '-print_mode when_changed' for hex

# Adding memories to file output:

proc add_mem_fo { iss ofilenm } {
    set sl [$iss info storage]
    foreach s $sl {
	::tclutils::list2array $::iss::storinfo_keys $s sa
	if { $sa(storage_type) == "memory" } {
	    $iss fileoutput add $sa(storinfo_index) 0 \
		-nbr_fields $sa(nbr_addresses) \
		-radix hex \
		-file $ofilenm \
		-verbose true \
		-format go_vhdl
	}
    }

    return
}

# ADAPT command below and "source add_regs.tcl" from prompt in simulator

# replace -format {go_vhdl} by -format {go_verilog} above when using Verilog.

# put registers to be excluded between '{}'

add_reg_fo ::tinycore2 register.log {PC}
# add_mem_fo ::tinycore2 register.log

