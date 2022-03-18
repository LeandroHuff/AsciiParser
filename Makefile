.PHONY: clean All

All:
	@echo "----------Building project:[ AsciiParser - Debug ]----------"
	@cd "AsciiParser" && "$(MAKE)" -f  "AsciiParser.mk"
clean:
	@echo "----------Cleaning project:[ AsciiParser - Debug ]----------"
	@cd "AsciiParser" && "$(MAKE)" -f  "AsciiParser.mk" clean
