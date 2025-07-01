int numWaterBottles(int nb, int ne) {
    int bc = 0; // bottlees consumed
    while(ne <= nb)
    {
        bc += ne;
        nb = nb - ne + 1;
    }
    return bc + nb;
}