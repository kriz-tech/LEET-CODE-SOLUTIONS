class Spreadsheet:
    def __init__(self, rows: int):
        # We may not even need to store rows, since we'll assume valid inputs.
        self.cells = {}  # key: "A1", "B2", ... value: int

    def setCell(self, cell: str, value: int) -> None:
        self.cells[cell] = value

    def resetCell(self, cell: str) -> None:
        # Remove, or set to 0. Removing is fine since getValue treats missing as 0.
        if cell in self.cells:
            del self.cells[cell]

    def getValue(self, formula: str) -> int:
        # formula format: "=X+Y"
        # Remove the '='
        expr = formula[1:]
        left, right = expr.split('+')
        return self._getToken(left) + self._getToken(right)

    def _getToken(self, token: str) -> int:
        token = token.strip()
        if token and token[0].isdigit():  # starts with digit => integer literal
            return int(token)
        else:
            # cell reference
            return self.cells.get(token, 0)
