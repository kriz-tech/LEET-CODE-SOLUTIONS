class TrieNode:
    def __init__(self):
        self.children = dict()
        self.name = ""
        self.hash = ""
        self.duplicate = False

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = TrieNode()
        count = defaultdict(int)

        # Step 1: Build the Trie
        for path in paths:
            node = root
            for folder in path:
                if folder not in node.children:
                    node.children[folder] = TrieNode()
                    node.children[folder].name = folder
                node = node.children[folder]

        # Step 2: Post-order serialize each subtree to generate unique hash
        def serialize(node: TrieNode) -> str:
            if not node.children:
                return ""
            sub = []
            for name in sorted(node.children):  # sort to ensure consistent structure
                sub.append(f"({name}{serialize(node.children[name])})")
            node.hash = "".join(sub)
            count[node.hash] += 1
            return node.hash

        serialize(root)

        # Step 3: Mark all duplicate subtrees
        def mark(node: TrieNode):
            if node.hash and count[node.hash] > 1:
                node.duplicate = True
            for child in node.children.values():
                mark(child)

        mark(root)

        # Step 4: Collect paths that are not part of any duplicate subtree
        result = []

        def collect(node: TrieNode, path: List[str]):
            for name, child in node.children.items():
                if not child.duplicate:
                    new_path = path + [name]
                    result.append(new_path)
                    collect(child, new_path)

        collect(root, [])
        return result
