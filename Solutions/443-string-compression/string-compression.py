class Solution:
    def compress(self, chars: List[str]) -> int:
        write = 0
        i = 0
        while i < len(chars):
            curr = chars[i]
            count = 0
            while i < len(chars) and chars[i] == curr:
                count += 1
                i += 1
            chars[write] = curr
            write += 1
            if count > 1:
                for digit in str(count):
                    chars[write] = digit
                    write += 1
        return write