class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def starts_with(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True

    def delete(self, word):
        def _delete(node, word, depth):
            if not node:
                return False

            if depth == len(word):
                if not node.is_end_of_word:
                    return False
                node.is_end_of_word = False
                return len(node.children) == 0

            char = word[depth]
            if char not in node.children:
                return False

            should_delete_current_node = _delete(node.children[char], word, depth + 1)

            if should_delete_current_node:
                del node.children[char]
                return len(node.children) == 0

            return False

        _delete(self.root, word, 0)

    def display(self):
        def _display(node, prefix):
            if node.is_end_of_word:
                print(prefix)
            for char, child_node in node.children.items():
                _display(child_node, prefix + char)

        _display(self.root, "")

# Example usage
trie = Trie()
trie.insert("hello")
trie.insert("hell")
trie.insert("heaven")
trie.insert("goodbye")

print("Search 'hell':", trie.search("hell"))          # True
print("Search 'hello':", trie.search("hello"))        # True
print("Search 'heaven':", trie.search("heaven"))      # True
print("Search 'good':", trie.search("good"))          # False
print("Search prefix 'he':", trie.starts_with("he"))  # True
print("Search prefix 'good':", trie.starts_with("good"))  # True
print("Search prefix 'bad':", trie.starts_with("bad"))    # False

print("\nDisplay Trie:")
trie.display()

trie.delete("hell")
print("\nAfter deleting 'hell':")
trie.display()
