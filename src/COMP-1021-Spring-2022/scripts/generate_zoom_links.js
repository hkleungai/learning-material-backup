if (typeof jQuery != 'undefined') {
    // Zoom Links List Column Numbers
    const COLUMN_SECTION = 0;
    const COLUMN_INSTRUCTOR = 1;
    const COLUMN_DATE_TIME = 2;
    const COLUMN_VENUE = 3;
    const COLUMN_ZOOM_LINK = 4;
    const COLUMN_ZOOM_RECORDING = 5;
    
    // Zoom Links for Spring 2022
    // Lecture Number: [
    //     [Section, Instructor, Date/Time, Venue, Zoom Link, Zoom recording link], ...
    // ], ...
    const zoom_links = {
        1: [
            ["01", "Prof. David Rossiter", "8 Feb 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09", "https://hkust.zoom.us/rec/share/K_eyCZHxQeS6sPir2mOO45xB0DwztHUeHhEm5Xtl2OZ6RQ_HW160uG-OqQU58cIQ.IMFARp2dTMS_G6BZ?startTime=1644286972000"],
            ["02", "Prof. David Rossiter", "9 Feb 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09", "https://hkust.zoom.us/rec/play/mYQvPKBPS-LxzIdtjMn4oPiv1pkoYKctCCBC0OSL6G8ayURqulkfM__0XswDo_2bkXp2XJFw3DtFQ1pm.0utjcd3X_hANLq5f?autoplay=true&startTime=1644396111000"],
            ["03", "Prof. David Rossiter", "9 Feb 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09", "https://hkust.zoom.us/rec/share/WXI-hE83kT32nf2oOyRFKPI5OwG6xew-wJeKB7sW3UG92oJTdBvgREYW9X-rtvk.I6JlLVO8VJz8d6VV?startTime=1644384153000"],
            ["04", "Prof. David Rossiter", "8 Feb 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09", "https://hkust.zoom.us/rec/share/BDr_Qt928RIcL-hfKaVebnMEuyhESZP27pz2nC3fnEppxSud7iykBqqhB7DwjV6A.W38u3UpoLclGo5aw?startTime=1644292063000"],
            ["05", "Prof. Wilfred Ng", "8 Feb 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09", "https://hkust.zoom.us/rec/share/Nlv_tBsmAKyaI45LTcy4rMqY0muCh1xhfEAHj4-OUneMRt0po50pHpPw_DUSxRAY.tION4ZRdu-PGFF31?startTime=1644305232000"],
        ],
        2: [
            ["01", "Prof. David Rossiter", "10 Feb 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09", "https://hkust.zoom.us/rec/share/J2BSktnV7pWAmw7JhYekJ382BwFOWzmK_BS5nd0Z0aoEuQFlNT6GyfeMG10TigCk.zkdgMcWp54RKuj5o?startTime=1644459269000"],
            ["02", "Prof. David Rossiter", "11 Feb 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09", "https://hkust.zoom.us/rec/share/MhNIa_ou-OkZ3FReFUUlRceLhWS39Ri4wZJtEXQBsukye3eM7fBXFQ6URTj1XLY7.QkGKfxunJePyWJS5?startTime=1644569184000"],
            ["03", "Prof. David Rossiter", "11 Feb 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09", "https://hkust.zoom.us/rec/play/c5c6JOIfzpho5Tu4WzNPMPZ8eslzcsr6FatEk7wpUmyDWU3r2aLY5Ivd6tq6U4QwpfxqDg_Su10tLYXP.J1Rn0l_qZgKswgbu?autoplay=true&startTime=1644556252000"],
            ["04", "Prof. David Rossiter", "10 Feb 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09", "https://hkust.zoom.us/rec/share/4ffHcDWAmaL-O0V3S2nNb2zsGDS7yKfBdyy0hhuAXP2hw6cxWwpM4yfatCGLsl_p.7Jcnmm6oRL586LyH?startTime=1644464670000"],
            ["05", "Prof. Wilfred Ng", "10 Feb 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09", "https://hkust.zoom.us/rec/share/rPjHZggQwuTa1o9rsiZdbLa3ZlSso5H5ps2CY1M-4MNjY3AzZ-RZfAEOE7y8OhSR.260YsekcI-xmRYk3?startTime=1644477835000"],
        ],


        3: [
            ["01", "Prof. David Rossiter", "15 Feb 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/j1KeC1Nx72EFiPcTmYHo5HP3pYPXzJ2Ar5BWuDzYpd0ssKLJ9rufQUFDT99yO4g_.JtUTQp0RTV4ZH-Jq?startTime=1644891740000"],
            ["02", "Prof. David Rossiter", "16 Feb 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/QKZkRd95KD_y3Bc49lixm5K0xK3q2l-u0v3JFShxLF1f8YJVxXrumFcSgvW_U-Wj.GmwRQtlFDsGADG1L?startTime=1645001118000"],
            ["03", "Prof. David Rossiter", "16 Feb 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/6D9yF9arVyOgRv9KqtHJdJN_RKfEZvGxP35J9aiyepOjdi7dhZOqBakmPVxR6IJC.qWtqC91u8DPrsEp2?startTime=1644988474000"],
            ["04", "Prof. David Rossiter", "15 Feb 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/pcbrgQT0pYfnTc8xpjbNFPpCATP6DIrFM-lKUQWya4ZdTfaYTIMr_VwrWczUVDfo.cMMO5K01GNp2ml28?startTime=1644896795000"],
            ["05", "Prof. Wilfred Ng", "15 Feb 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/sZoAh7JHVSKLBgqALCqUg3D7KmATmrbBepNnKDIu1uDP-tC10cxmiBEX4ssKN150.Sml0kAzukwf62YoD"],
        ],
        4: [
            ["01", "Prof. David Rossiter", "17 Feb 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/v4aVy4G3QmlIarZp6xr0-6wHpjMNsGULupyuApl2jmoL0AliWcRqQBu8cVFaKS1A.uM9DczLhkrOkiKJ_?startTime=1645064162000"],
            ["02", "Prof. David Rossiter", "18 Feb 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/WMJMpp-TrCu4jRIKMfS2bkbco1SmcvXPI38P-1AwQOmCmTQDMQs9B7WBCjdY_Gj0.YIwrmf1H8Esb3MrO?startTime=1645173710000"],
            ["03", "Prof. David Rossiter", "18 Feb 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/e4YsjbQsWT61tPoTH34A5qep1Kn774jOSuH1xwy1Qf0aedu5BmHcFcFUHgZ-cik.MdQyCikb3-N3FQb7?startTime=1645161628000"],
            ["04", "Prof. David Rossiter", "17 Feb 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/4sEIhf72dx19TzeifWrZrDvTl3oKpFbOA8qC7TmoOx14IJzGmCRq_hpgDTN9Xd2B.21F6Ec0OFLgD2TKJ?startTime=1645069933000"],
            ["05", "Prof. Wilfred Ng", "17 Feb 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/vOvi2zgn-wbF2MAxUjSWq0XDKDKy9x7zmXdzXRfkb1_ecU7PW4eJIkokvZOiexes.0u7CSzwQlOY9CGfd"],
        ],


        5: [
            ["01", "Prof. David Rossiter", "22 Feb 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/ZWEsRQrdQ6joC5j9yt57lSCQYCGA9jsMVfFlIMG_tz5ooXOaSFgF8GovMT09eHwx.JM-rpBJvLZH1_Oi_?startTime=1645495744000"],
            ["02", "Prof. David Rossiter", "23 Feb 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/n1NSPrefEtOkIPW_cqbO8grpZhbcFk0hH8pW42oXZrVHy8DLRt4mBtPZ34GMWnkM.QKT7f_j_3sRuQ3IW?startTime=1645606005000"],
            ["03", "Prof. David Rossiter", "23 Feb 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/EvvI86fCkCN0kUyLc9Ei7J8lPvuIMdkuVGdMKaIdTEY_skEbmIbN5o2oDiJtgRyH.SRHgGgImHjbkTStt?startTime=1645592852000"],
            ["04", "Prof. David Rossiter", "22 Feb 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/ZzftqvUV_z8w16EKQ_SG7ScWKfKhfeZX56eorFBzsT4ZzzUY3QnKmFkmtJQM8bfu.dFWlb7GmdrUMJ1t-?startTime=1645501526000"],
            ["05", "Prof. Wilfred Ng", "22 Feb 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/5yOU7pEc1cYy7-gNSY4AZ0_NuTz0rDK9SSjO_-yuKKZc1DOlFP-bqzwrvHTX3Szd.uNy6ojELUzVKeu3Z"],
        ],
        6: [
            ["01", "Prof. David Rossiter", "24 Feb 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/aEXhe7hxA8EzYIFwP4se0rO0J-ai0vX7dXbiZLb9LOIZ7wAiZ6cBUMteRzkq7yjE.wSZ1lF8wwBMonQVy?startTime=1645669281000"],
            ["02", "Prof. David Rossiter", "25 Feb 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/yq4SLLrUWj07cUIfOkKNMDLnaKx4QNLjDcdMIIKBi-2K2Njw8H2Po08RPIYOiHMu.IdTnZhwkncVhK4Up?startTime=1645779026000"],
            ["03", "Prof. David Rossiter", "25 Feb 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/lrXvc_OtNtB7FPoEAoGWdy6a-zMc57DtgHcwqkbVObKWNFaOQD4z85aDy2M_GcAf.gzuu0R-4xcdo_N6g?startTime=1645765786000"],
            ["04", "Prof. David Rossiter", "24 Feb 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/eZ21K2J6DjYLc8CPRfw_Dtll4HsbDaFb4-Pknxg8GP6Ihf-I6zNBPXYs6oTePaWl.xN0AjKCvbOEa8pax?startTime=1645674748000"],
            ["05", "Prof. Wilfred Ng", "24 Feb 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/play/uodWXvSjtV8XaR-poul6MjS-eOKefotZk7kBSkpxNpN-9m2b5zmd9f5CWb0qI1cIbl_yXWSk6HkumLA.P4PXQq94KFcGz2Kk?continueMode=true"],
        ],


        7: [
            ["01", "Prof. David Rossiter", "1 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/BpQi8xGmnywhDKJ6jAe3aXPaNjQkyBBYmHGQPWpGjTi94hg7wovTgDkGjOu3UrId.YF4Qn-ZUFSfu7XbR?startTime=1646100593000"],
            ["02", "Prof. David Rossiter", "2 Mar 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/Pn3U6XKkiJuhcvNEyXJPrpvs8FvXUU8NM_x7WR-zRXvN0vGFhLlRInSHqPtY-_1b.wJBPfaObtfjeJQI6?startTime=1646210599000"],
            ["03", "Prof. David Rossiter", "2 Mar 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/FjlH6H9m5GI8MBkwIDBXUJzhduLKinO2Asr4WiSbdd-QHTe89_GFxv_QzG9xlCvE.AoO3N_SGHu_F5mf1?startTime=1646198320000"],
            ["04", "Prof. David Rossiter", "1 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/NJjaJSG-4jOtRtNaCOB0fBdsLUv2F1nSuxfeOF2IwEuVi6dmqfIaqLf0AU8iIYk.hj2jTFaXdxkjjQot?startTime=1646106401000"],
            ["05", "Prof. Wilfred Ng", "1 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/0QN0C1eXlyUVqRkMTEizCGJ0QajM51urCEP-NoKwcOo1xPw363jzKCklSDPofZd-.Y66gHsL0PkmsgQ7h"],
        ],
        8: [
            ["01", "Prof. David Rossiter", "3 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/p7ExWYpB_jcYi28CQfelDMYlTEVh2AnfsJO_HhiTne2ZKHc08p2Y4a4V6AY_lxwv.dmO-zuiG-2bkrkq6?startTime=1646273316000"],
            ["02", "Prof. David Rossiter", "4 Mar 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/2wkMGbOK84gU97UsPL__DYb5fwEn0z4N5bM2XUahiDRElCU-X4QV95u_rB3KpzaI.gO1MnXlpM0igV6AS?startTime=1646383668000"],
            ["03", "Prof. David Rossiter", "4 Mar 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/HQYeu9A8b7OOJzSmBtbShlsmzahTA2S-C6tsQYjEQloENhSBY1X-ocItbaNzSx5g.eKFhLyQS4luwvmru?startTime=1646370654000"],
            ["04", "Prof. David Rossiter", "3 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/2xScDcqBitxY0eKhjYCNncCBmo65q6x7f3GCKDjLD7p_ZGuKRXf7qkZZQgBChjS-.f1OjJvZdEVtpeelb?startTime=1646279123000"],
            ["05", "Prof. Wilfred Ng", "3 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/k9nTp2DQmdUjEF6dtjjKyxe__W3jfn-WVSheS2MnaUBEHGGEMSWO8r3Sd-ZgAjRN.VrNb-PCoOk6Ka8cT"],
        ],



        9: [
            ["01", "Prof. David Rossiter", "8 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/LNotXjaIfrnZVqG0KcstiyL9UAZO_aJ3UeKjNZ2cycnaq_vlBlARDsEjAmF9niZ-.D4dSB7h1qi8HfFEs?startTime=1646706001000"],
            ["02", "Prof. David Rossiter", "9 Mar 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/bUbPF649GEQyP1Ur_DmwnYkZUuvC5g6fSAD33DmV4TXlY-uoROm64oBfgdtSNhdK.-ONI89hsJ65C_BDx?startTime=1646815685000"],
            ["03", "Prof. David Rossiter", "9 Mar 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/bSgVv1JGPm_OGuvF3ipGKAvaw-rnJFmabPGwRQQkh8NBOdA_e3X0xOmPE43JNUO7.y8MOC8P_mbG9I9Aw?startTime=1646803269000"],
            ["04", "Prof. David Rossiter", "8 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/CEPN85pP5XHsZ6EGMzmKPKPZKMSMPhdL2rQR0RjHdk_MLms7WlkgBjMdKT0chZte.84MxCMe3Ckt7TD6K?startTime=1646711318000"],
            ["05", "Prof. Wilfred Ng", "8 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/K74rlEkfi2duaQtHWGmngCDUTXthZeX6_Jh1LqRkDJ9a9M9nmiBKhQ_SUvgbyUo0.ryxTJFvkme0PakzT"],
        ],
        10: [
            ["01", "Prof. David Rossiter", "10 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/play/XnQHSemPhpMVcKwMVLYhYZvripbdiyiihq0XDYKLHoXQw3v945bm_--N9QPpn8IxGehLFW8VsGTtV-Ax.HrMGha-8hZGt2P4W?autoplay=true&startTime=1646878606000"],
            ["02", "Prof. David Rossiter", "11 Mar 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/play/85SQmeEN2AU45E5gORKAog4IBGqyoM5V2D8ceMZTIxC-sQIorpOjflcxKbh0a7yLeWCYusFNucoa3NTi.Io9OzjQBi5Z1TDXe?autoplay=true&startTime=1646988490000"],
            ["03", "Prof. David Rossiter", "11 Mar 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/play/ZoyypiOKC6astZEZhBdapeXRUo8hD8C0ia7wEYz2c7Ocnb2UFuQYQzUg_EeP1ZNVyaJSPKY1QeVvY5B9.sgFj7RARZbcKkvJu?autoplay=true&startTime=1646975815000"],
            ["04", "Prof. David Rossiter", "10 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/play/YlI2J_Z-rZBSTAKiywX79tRGTVZrs6NmcH01v1fp6kLPKVSF1Tasc_qDoZvfti5Vm_rg3q_1uL4dYg5N.n_A9Mgu4bEEoidjD?autoplay=true&startTime=1646884023000"],
            ["05", "Prof. Wilfred Ng", "10 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/3UFAfEQf6mrce0Vz9HhWBIIggL7yIBIzuxYc0sXG2QxUDM6-8Fn8LBSqsA_HUyAq.SvBIlmY0zAE4mJi9"],
        ],



        11: [
            ["01", "Prof. David Rossiter", "15 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/X0litUk1saL0O0mk1ntrOps0Y2j8eKKQyCKipLFgjBmJPEFUxZrO5rkebo62WvBX.uOoI2BxIsahDvExJ?startTime=1647310745000"],
            ["02", "Prof. David Rossiter", "16 Mar 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/iU1XDkT0T0qYPMt_fJ3R3afZ9Y9bzjw-oMY4V0Ji5MryGkS5HGf3vqTKGuNCyn0o._yZqoewIGCAHLnFU?startTime=1647420481000"],
            ["03", "Prof. David Rossiter", "16 Mar 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/UwFrH7a5-cZEASm9j11DF5mu4ddmMcbNM-OY9J0Wcx5zsPT04IDkkKEQhJF_YLvV.zmcu1nL58Jkt1jSF?startTime=1647407745000"],
            ["04", "Prof. David Rossiter", "15 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/MfYL3rnzRtkYjAi33h5i3K4lI6VGz7yG5IzTkdEUlhx3PvuqJPtcTwrgId57D5Z6.1rgwb6gX32-3-fdg?startTime=1647315947000"],
            ["05", "Prof. Wilfred Ng", "15 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/YL_RA8LSdwLaAAmiaropTfxXvKRSroQOKSJ_ajdApnC19s7nNL1YKjVx5GXMLhXs.XW55jT1tfvdlixzp"],
        ],
        12: [
            ["01", "Prof. David Rossiter", "17 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/0l_hEKYafczTTI5p5hbPCeXZfomUFW5kkKcMMvJXR2mqqf18jPhgc1R7Fs6NceJv.AwxUhlakVs2QOsBN?startTime=1647483858000"],
            ["02", "Prof. David Rossiter", "18 Mar 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/mYJw4AXtyjOlbScQc0J8gk8MHAehqat4aPIMbTEyT8EoXwUg71NUzAck-YNJ_0na.5UGqw4gg5wlTQLEL?startTime=1647593501000"],
            ["03", "Prof. David Rossiter", "18 Mar 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/mbRtxn4E00Mwq9jktgvcTJVzNesYcwMA30vcEMJokADS9QPG7qMLHRhlXLchGI2V.jkaEQHkoTErH7KP7?startTime=1647580635000"],
            ["04", "Prof. David Rossiter", "17 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/u239kt_Yj6OQImJ8RnMDrxdVcou2ytQba5R76s23lKHExdCYY__lsAQSFdVT.dd2QRHY1ysTeTcXu?startTime=1647489001000"],
            ["05", "Prof. Wilfred Ng", "17 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/h0TCwZHbiw6V8kqVIA_oe6QRggoi4-_MzFoGrTfev64275OENtwBusuQiT6P8qtw.qP1a9n4o0TBv5RQ3"],
        ],



        13: [
            ["01", "Prof. David Rossiter", "22 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/_eKUIN6E5yvynqDvFUpLXdBtPElNpv6c0j-VV3VU10RWGTf1XbRNiDpGHYEh4WLa.NVS-1D3bpBZLSb5E?startTime=1647915377000"],
            ["02", "Prof. David Rossiter", "23 Mar 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/dfi27DcpBhLFGKG0ZSWlgMk8saV5S2gFEFVGQ-KGHLBW8sAmrCK2Ex2-H-urwNI.7G56j_kBxGOb7DIG?startTime=1648025145000"],
            ["03", "Prof. David Rossiter", "23 Mar 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/EtzuW8iScY0W1bVeeFK8xt55YjQf-yiruJ_bcMvTWKK0ZDHDNUjNErRSqYsf5vvE.VqcXLoxhp8j--QZa?startTime=1648012605000"],
            ["04", "Prof. David Rossiter", "22 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/H-s_qOnRX7hbb6tf4HC3jpDg-yWzyWnHVqLYuPy2c68aLGktuUgVSdGixthx3OcA.rJ0JYFh0dUkvs3Cy?startTime=1647920798000"],
            ["05", "Prof. Wilfred Ng", "22 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/dkTW1Kk44mIBq1mFIgWtf-1Mf_iVlVZ7uuAw0UZsaoqUhNSJ9AnoZW9lo3OuPYQ0.1O2ds_-_TiN9uRoI"],
        ],
        14: [
            ["01", "Prof. David Rossiter", "24 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/0cRPlRU69cMMU_puVWs2DhKLnlXAOrIPsXF21f-ATLkTIhuZjoKFOoLVzZwJeuuL.bHWVrdw2K0CIR0xS?startTime=1648088095000"],
            ["02", "Prof. David Rossiter", "25 Mar 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/qV4QQu1J2VOue3zqhRRQCm6m35YU69KUqwnlPZAfRJfobTOJz8K9QvVwDmVwZaoK.HrojWwQVgLkMyg3L?startTime=1648198271000"],
            ["03", "Prof. David Rossiter", "25 Mar 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/gpMt6LGz3YTifmfd5SrI3LGHN8mYkRV4uTgTBWB5c4zQdflRAc9jqriMpNY9Vtir.jsbC5q065c17KGKW?startTime=1648185604000"],
            ["04", "Prof. David Rossiter", "24 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/L-k5YLqVkk0JItkD_0cp7d_egIwabymsxmo3bb3z7iRyz2yd9q822ZD6OKeQTKWl.s7-6ssT85uGz7HNj?startTime=1648093658000"],
            ["05", "Prof. Wilfred Ng", "24 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/9sLNjD-0ymlYhGAkB0E9rOkfgduVjF60O3YGS8ttzyw2A8Fpq3Q5lB7N-N0MDf05.QxTZ9sEMXLQCpCZv"],
        ],



        15: [
            ["01", "Prof. David Rossiter", "29 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/J6EYaes7_WIpuM8X146xf07Ilmy4d2IaHcANVw9BEa_WnZB-PTNsS24c3E1fTrkI.Q82RgOpdgZ_ftMjJ?startTime=1648520329000"],
            ["02", "Prof. David Rossiter", "30 Mar 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/srqo7B8hMbkz6oA2HqBwWuZwMsSJZ82RpPKMeiHMuJlNfsqI8xDWZFKvKxUCl4Y.7keIP-nPe202_Fql?startTime=1648630127000"],
            ["03", "Prof. David Rossiter", "30 Mar 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/Y2-TM2CTpP88X6hH3Xy_mLzw4_EAMaH2yLvmL7S4_nfVMyDF8vRqmt-Etn6el0TA.uR939mc2Hrd3mjf7?startTime=1648617472000"],
            ["04", "Prof. David Rossiter", "29 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/o1Ndb3M7k8s2x2_b5PkQUEFoWC43LdE8YmR94usQfuPXfMMHXi3_OmSMnTLH-5Lt.N3FqIaW29o8NH3wj?startTime=1648525966000"],
            ["05", "Prof. Wilfred Ng", "29 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/9ACYQ_AUNMYxCZ3gEwCShV557Zj-_NaDL-f2fArmpqDCDzStpSV6pEhza2cAMwUX.0E7OQ5gDnKTmgP0M"],
        ],
        16: [
            ["01", "Prof. David Rossiter", "31 Mar 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/S9zPW05rndfZgjh2xPcQVLFYWk9CzUjuOSymOzRHsVrjWGtxYhossZvJTf1-3I-0.7v7sKtFNOGzJI-rm?startTime=1648692933000"],
            ["02", "Prof. David Rossiter", "1 Apr 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/eTtG5aFU1vIG-fN8t2TfjU7_cNxYkJyV5ntodtvXDYno9zF5B6g4WehQmZToGzgy.CQaEgaqwUY_FMTJO?startTime=1648802675000"],
            ["03", "Prof. David Rossiter", "1 Apr 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/LcfzpOuf7IKNkCSvUDQ0gRLENXjlp0v9Sueu6PMDyL96n_MmK0GGXmY3FarNlu6G.a38wRc-adfk0HYC7?startTime=1648790533000"],
            ["04", "Prof. David Rossiter", "31 Mar 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/GAnyix_tAHaG7YSqGSP2AjsdBb_3l_zaaN4oBGP0NP_bpOOQTJpohjFHxXts7gUM.YvZzlsjtYzglF3AH?startTime=1648698476000"],
            ["05", "Prof. Wilfred Ng", "31 Mar 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/2reeim6-WQaHvw9uZV9znQY5jzzU9IyavYkGDWwE9A0GnanhcQTZJQGpb5ffNQvb.gTu5oF8daw7KrWnJ"],
        ],


        17: [
            ["01", "Prof. David Rossiter", "7 Apr 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/ujP_YvBh62VSlYczaVIOTXsvNrw73HMXwaNCh4IYHUVnSi4QSspCMJPNsMHMTxbS.IHZBWrcK_7FxIuMp?startTime=1649297939000"],
            ["02", "Prof. David Rossiter", "8 Apr 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/1yq4i-n698LpEIwj0_6_EoqyoVD4nQogHHFT1I9n-cws0IRIlYJhqt2-NIM_-d-f.o11Bv9vigDap1c-s?startTime=1649407920000"],
            ["03", "Prof. David Rossiter", "8 Apr 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/0NETZITT_Pjf8IAKqTnPblLEO8UzSLjquRW7fkIXmxKs1GVXoyk4q88fFt9Eqy47.jr-NSwa27sAjCRwc?startTime=1649394843000"],
            ["04", "Prof. David Rossiter", "7 Apr 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/kbBwgcxs_EmmRvHko2IresMr8eDfxTt9xYvrR-zLQhRYdGToW8SjMkwF0K2JYdc4._XgzgGjJb9IXfeV5?startTime=1649303192000"],
            ["05", "Prof. Wilfred Ng", "7 Apr 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/wCxrSS5L1paN8cekaIJe3y1mlRA54F5pyEdVIxacJZ-__Fpl4jw4tFaBu9BARo-4.hJhKQ1jCVcHQnAAX"],
        ],



        18: [
            ["01", "Prof. David Rossiter", "12 Apr 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/Ymu15OdqvGfDe0rofGSNFo8o2BTaNPC0CsenMHMJjeQoLyWbsvFa3mirthpgK6VZ.YN2zWOzmDXTrfcLh?startTime=1649730134000"],
            ["02", "Prof. David Rossiter", "<strike>13 Apr 5:00pm</strike>", "", "",
             ""],
            ["03", "Prof. David Rossiter", "<strike>13 Apr 1:30pm</strike>", "", "",
             ""],
            ["04", "Prof. David Rossiter", "12 Apr 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/Nc5p3ikFmNwUBib93A3aaaU-sMed2o0OJlZJiS0d8aL-6Bxr4YdNixyzaYsfkk4f.qw4BggXp7LuKUqNL?startTime=1649735430000"],
            ["05", "Prof. Wilfred Ng", "12 Apr 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/pR9VD_jmymXU_HUjXF1wRaEyHx3bgbcFcX6GUzAvxFnWqpRK4i41Hgk0JLYGkvul.TQoCwLcvZp7Xby1J"],
        ],



        19: [
            ["01", "Prof. David Rossiter", "19 Apr 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/2dXEi2jp1sicqlSWZWOEppfv862aTaWFzxOWwu5QYdboMCTff0mphurhvEEQOlvo.dYmoCConDJOi_jIE?startTime=1650334616000"],
            ["02", "Prof. David Rossiter", "20 Apr 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/Vdz313F1e0NN6QNU3TaxYe7js3ulLlZajnK3FYDBEa0peAyi_9snLdyyNvUhFsZr.ISl19tAZvpIkuqwj?startTime=1650444427000"],
            ["03", "Prof. David Rossiter", "20 Apr 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/JHFlHtl3rwA0knEm3ESkqM5y4ouezc2ziVukm4jV3Mi_EhoX0kawpxoMSS6ecpiU.sqKFuUqLahiNCl0a?startTime=1650431451000"],
            ["04", "Prof. David Rossiter", "19 Apr 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/lA8QdH4xvST8sV0j2qktBtIuS0h_85x7v3BAv_zAWL4dcE-vmVs7eFtYWlNU2QFB.i39OX0QXZy_pkqA6?startTime=1650340103000"],
            ["05", "Prof. Wilfred Ng", "19 Apr 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/UnA28zCbPGEUCN5_8HBpRN__lhQrRPKp1tjXRoYSysA9sqtmqrQiYztDkCHq8CIs.tdi1tJbhVdbdDIri"],
        ],
        20: [
            ["01", "Prof. David Rossiter", "21 Apr 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/fc5DSLIeh_Zo6yxI8F0t_bwcgLkQ2k9eKRhQO2708CHOMPM52aG9g22lf7v6ErL7.COZXml32HXtutrcr?startTime=1650507420000"],
            ["02", "Prof. David Rossiter", "22 Apr 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/QmGeKN4EybomeCYGpLZADSpV9uB3JT-UOHuDPFfr3hHY4VtbVTdc04BRs-PT_dFc.tjV5LaGPeuaTFbLf?startTime=1650616683000"],
            ["03", "Prof. David Rossiter", "22 Apr 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/6RE98WWNgHl5uwfQ9XV1MslOkVqKztK1i2aLOEwIz0JqmG4Nwasw53O9Srgb-XMs.bZSIbxw2WPL1PBHv?startTime=1650604601000"],
            ["04", "Prof. David Rossiter", "21 Apr 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/4yXp_HrT0wDl68imyU6DdskMdznzCyYFmubbJ6g18Vi9_oN8wwRLtoEcikN1VMyT.eUQJuJ04Gr_3W-jr?startTime=1650513183000"],
            ["05", "Prof. Wilfred Ng", "21 Apr 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/M1_g19V1oWX9PjhTOe0FREXygD_yrOPnKMFD4gtCMS5vmOSM7G6MrdLvL4sMYhw.seRvFY-Dmgkh9Tzn"],
        ],




        21: [
            ["01", "Prof. David Rossiter", "26 Apr 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/gY_AiiE31N38038GJ14zS3_u1SXTGiTts_qZ_hofQSDxxyUSjU_ecjxNQ0ZR7Zfo.61uQMnzGrF2S2qU9?startTime=1650939389000"],
            ["02", "Prof. David Rossiter", "27 Apr 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/ujEAQhTIXjdXtxawc96JFjueCKu3k_Upk1RjtXp9SV1gR-hqiycXRFhwSn-Tl5Rk.dFFS3FU-28F806UR?startTime=1651049169000"],
            ["03", "Prof. David Rossiter", "27 Apr 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/9hpqG5BqyK-wsKpgH8UKg5Kf_Nop51YWNTqCV7u1E7r-HVuMoJLFcW76edC2NOOR._kJt4T72GNxFVSSR?startTime=1651036541000"],
            ["04", "Prof. David Rossiter", "26 Apr 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/KfLegbsxhGGNoHZ5lWEkMRCccfQNc17PTdOL_ijoCf6KeqfKBa9SFg9vLWvz8rmo.Qwn5IwI6lKdkvzA3?startTime=1650944712000"],
            ["05", "Prof. Wilfred Ng", "26 Apr 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/EB9nJVXI7WC_gkWlDe8VYzPv-PbXDcNfmRbUOxSaGr8NoPR0GdFFmyjXdryL-9Bn.hZczz7DJyw89yTBy"],
        ],
        22: [
            ["01", "Prof. David Rossiter", "28 Apr 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/A-pQ0Wse0uc0FQKlwz2em-1V5sk1XQxPKzg1KlcfKPKdDPCBN9j7hQxo2d2BfgZj.KicCn7NiRSDxPwvH?startTime=1651112027000"],
            ["02", "Prof. David Rossiter", "29 Apr 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/3VPTHT8WPlT3HS3Myr3zW0bOtAXe-onAqK7q9NSKsjFAn83M5-E8kBSfpudbf85j.MSfx0dVjzniCL6-X?startTime=1651221824000"],
            ["03", "Prof. David Rossiter", "29 Apr 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/nEkmQkv5jeYBFwsWEvJtQbyaFa8uQGCR7dDJmG5_DN70r6lrgKOTTwkAuom4xTBt.em2nG2dCsvJH6Vk8?startTime=1651209325000"],
            ["04", "Prof. David Rossiter", "28 Apr 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/shWhxYfnsl02FPT1d5jXofEaNy0YR64RsBbNyPfnXof5K_iInSrxgaeXntZDJC9p.PrqE3ytRGvsF5s_W?startTime=1651117898000"],
            ["05", "Prof. Wilfred Ng", "28 Apr 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/QZ8rFNNNdCiyztWY9wHHItTy72skyDfb8RxgZInGKhhbMwqkS_R4Q5HHm4X73QB8.8HExh_G4MxEdxN_w"],
        ],



        23: [
            ["01", "Prof. David Rossiter", "03 May 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/MDdjj8fIsmY-BiLPQSFPmuu0wegXgqhTsgy1B7ABlyTG6Eh0-DA2Hm3aTmyxPQW-.Ez_5yBg0h2Dw5Y43?startTime=1651544203000"],
            ["02", "Prof. David Rossiter", "04 May 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/LlDvj0Z4gMO_AZ322J43hlGur6Ie_UqbI2eS7zvtBiqZJ1QgnCrlKqgwcjAG0Pf5.gbrQtxFyDsBhYHEJ?startTime=1651654127000"],
            ["03", "Prof. David Rossiter", "04 May 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/sWZIz3jgLAKJ8knnAzIpHw9mx-jVdbyWWJapgsbLnuW7U2Ok1dvjFmsOzfXqmHi3.b1RgoDX2R5GdIdvR?startTime=1651641353000"],
            ["04", "Prof. David Rossiter", "03 May 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/tx4IhJZRRT-G2wDkehY3Y9dOK5rnrJSgitqOVw0MHlvaaOlYlP_F_V0DxRSwYgQG.xXnkoHJa_ub_22gh?startTime=1651549517000"],
            ["05", "Prof. Wilfred Ng", "03 May 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/yEEGajiiDnwV3XRo7X52Mk-oR5KAYmH6FyHTAvdXKh3qLieDgNREP7ziRSzU3fHa.E-kse9VaEIyJBGLB"],
        ],
        24: [
            ["01", "Prof. David Rossiter", "05 May 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             "https://hkust.zoom.us/rec/share/nZ2EEyIRppxg04FCuSx360tBmA-BLdLg-J2zFgKr24jHxlELW908oyFpwVRotPV0.Jg0v64UAyk8S1_Y6?startTime=1651717141000"],
            ["02", "Prof. David Rossiter", "06 May 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             "https://hkust.zoom.us/rec/share/6n19wvBrcInEpdb7WU92XGu9rRAzSh--Y1O070QD8WiDmJ1cDrTEle75shMUP5TG.4274_R_tXyBs_fEU?startTime=1651826781000"],
            ["03", "Prof. David Rossiter", "06 May 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             "https://hkust.zoom.us/rec/share/S8xdngW0xw6btZ6RLktJfd3hRmrocukvFLVqFMakyGWWlFIITN89olWgFpji2nAg.970KbmK7_1vPX2sa?startTime=1651813950000"],
            ["04", "Prof. David Rossiter", "05 May 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             "https://hkust.zoom.us/rec/share/pPrp2iVk-7neZOyI-UFMuuUXzMi11nw7ZlNMryYMx7UEP5cvn0zDhgw7cjjEL3QB.BiZXnLKt3WN9yMNk?startTime=1651722231000"],
            ["05", "Prof. Wilfred Ng", "05 May 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             "https://hkust.zoom.us/rec/share/xDrEKSgkCymP5hBQxO62iHn4KnAU-Mwn_DgA3sqBvwJRuX7-CFR8squCs_rwB7zB.ctWZZelVhLqBNUzX"],
        ],


        25: [
            ["01", "Prof. David Rossiter", "10 May 10:30am", "", "https://hkust.zoom.us/j/97659759653?pwd=WE5ZM1FJVTErdTFTY2JyZmhlOEMyQT09",
             ""],
            ["02", "Prof. David Rossiter", "11 May 5:00pm", "", "https://hkust.zoom.us/j/98729153891?pwd=bER0Uy9WT3NmSk1ESGVxeUtKSjhrdz09",
             ""],
            ["03", "Prof. David Rossiter", "11 May 1:30pm", "", "https://hkust.zoom.us/j/97865868783?pwd=blNzaWxSeDhVSnIyWXdOQnZCL3Z5Zz09",
             ""],
            ["04", "Prof. David Rossiter", "10 May 12:00pm", "", "https://hkust.zoom.us/j/99778800382?pwd=Ti9TL01jeWJ4Ly9LV0s1YVpBeHAzdz09",
             ""],
            ["05", "Prof. Wilfred Ng", "10 May 3:30pm", "", "https://hkust.zoom.us/j/91999976025?pwd=L3Ywc1lUcEw2aEFQdk4vL2E4ODB3UT09",
             ""],
        ],



    };
    
    $("zoom-links").each(function(i) {
        // Lecture number
        const lecture_number = $(this).attr("lecture-number");

        // Name
        const name = $(this).attr("name");

        // Meeting reference
        const links_key = lecture_number? lecture_number : name;
        const is_lecture = lecture_number? true : false;

        // Cancelled sections
        const cancelled_sections = [];
        if ($(this).attr("cancelled")) {
            $.each($(this).attr("cancelled").split(","), function(j, section) {
                cancelled_sections.push(section.trim());
            });
        }

        // Add table
        const table = $("<table class='zoom-links'></table>");

        // Add header
        const tr = $("<tr></tr>");
        tr.append($("<th>Section</th>"));  // section
        if (is_lecture) // for lectures
            tr.append($("<th>Instructor</th>"));
        else if (name.startsWith("support")) // for support sessions
            tr.append($("<th>Instructor/TA</th>"));
        else if (name.startsWith("exam")) // for exams
            tr.append($("<th>Room</th>"));  // room
        tr.append($("<th>Date/Time/Venue</th>"));  // date/time
        table.append(tr);

        $.each(zoom_links[links_key], function(j, fields) {
            const tr1 = $("<tr></tr>");
            if (cancelled_sections.includes(fields[COLUMN_SECTION])) {
                tr1.append($("<td rowspan='2' class='section cancelled'>" + fields[COLUMN_SECTION] + "</td>"));  // section
                tr1.append($("<td class='cancelled'>" + fields[COLUMN_INSTRUCTOR] + "</td>"));  // instructor/room
                tr1.append($("<td class='cancelled'>" + fields[COLUMN_DATE_TIME] + "</td>"));  // date/time
            }
            else {
                tr1.append($("<td rowspan='2' class='section'>" + fields[COLUMN_SECTION] + "</td>"));  // section
                tr1.append($("<td>" + fields[COLUMN_INSTRUCTOR] + "</td>"));  // instructor/room
                tr1.append($("<td>" + fields[COLUMN_DATE_TIME] + "</td>"));  // date/time
            }
            table.append(tr1);

            const tr2 = $("<tr></tr>");
            table.append(tr2);

            if (cancelled_sections.includes(fields[COLUMN_SECTION])) {
                const td1 = $("<td colspan='2'></td>");
                tr2.append(td1);

                if (fields[COLUMN_ZOOM_RECORDING])
                    td1.append($("<em>" + fields[COLUMN_ZOOM_RECORDING] + "</em>"));  // cancelled message
                else
                    td1.append($("<em>(cancelled)</em>"));  // cancelled
            }
            else {
                const td1 = $("<td></td>");
                tr2.append(td1);
                const td2 = $("<td></td>");
                tr2.append(td2);
                
                // have lecture video: click for videos
                if (fields[COLUMN_ZOOM_RECORDING]) {
                    if (fields[COLUMN_ZOOM_RECORDING].substring(0, 8) == "https://")
                        td1.append($("<a class='zoom-link' target='blank' href='" + fields[COLUMN_ZOOM_RECORDING] + "'>Click for video</a>"));  // zoom recording
                    else
                        td1.append($("<em>" + fields[COLUMN_ZOOM_RECORDING] + "</em>"));  // non-link message
                }
                // no lecture video: click for Zoom link
                else {
                    if (fields[COLUMN_ZOOM_LINK].substring(0, 8) == "https://")
                        td1.append($("<a class='zoom-link' target='blank' href='" + fields[COLUMN_ZOOM_LINK] + "'>Click for Zoom link</a>"));  // zoom link
                    else
                        td1.append($("<em>" + fields[COLUMN_ZOOM_LINK] + "</em>"));  // non-link message
                }

                if (fields[COLUMN_VENUE])
                    td2.html(fields[COLUMN_VENUE]);
                else
                    td2.append($("<em>Online only</em>"));
            }
        });

        // Create collapsible div
        const div = $("<div id='zoom-links-" + links_key + "' class='collapse pt-2' style='overflow-x:auto;'></div>");
        div.append(table);
        $(this).append(div);
    });

}
