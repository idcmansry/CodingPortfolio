def load_file(doc):
    return open(doc, "r").read().splitlines()


def assemble_genome2(dna_list):
    for idx in range(len(dna_list) ** 2):
        if len(dna_list) == 1:
            return dna_list[0]
        idx1 = (idx // len(dna_list)) % len(dna_list)
        idx2 = (idx % len(dna_list))
        if idx1 == idx2:    # Skipping whenever the indices are the same.
            continue
        term1 = dna_list[idx1]
        term2 = dna_list[idx2]
        if term1[-8:] == term2[:8]:  # The overlap can only be 8 characters long
            dna_list[idx1] = term1 + term2[8:]
            dna_list.pop(idx2)
