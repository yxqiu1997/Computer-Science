const char* msg_to_usr(int num_tries) {
    const int rsp_cnt = 5;
    static const char* usr_msgs[rsp_cnt] = {
            "Go on, make a guess. ",
            "Oops! Nice guess but not quite it.",
            "Hmm. Sorry. Wrong a second time.",
            "Ah, this is harder than it looks, no?",
            "It must be getting pretty frustrating by now!"
    };
    if (num_tries < 0) {
        num_tries = 0;
    }
    else if (num_tries >= rsp_cnt) {
        num_tries = rsp_cnt - 1;
    }
    return usr_msgs[num_tries];
}
