import BaseRenderer from 'https:/hkleungai.github.io/mini-web-component/BaseRenderer.js';
import vis from 'https:/visjs.github.io/vis-network/dist/vis-network.esm.js';
const isFirefox = typeof InstallTrigger !== 'undefined';
class ChartRenderer extends BaseRenderer {
    constructor() {
        super('Chart');
    }
    build() {
        this.innerHTML = (`
      <div>
        ${isFirefox ? 'Sorry to disappoint. This won\'t work in Firefox.' : '<div id="myChart">'}
      </div>
      `);
        return this;
    }
    attachEvent() {
        if (isFirefox) {
            return this;
        }
        const highlightBackground = '#008000';
        const highlightText = '#ffffe0';
        const nodes = new vis.DataSet([
            { id: 1, label: "COMP 100" },
            { id: 2, label: "COMP 200" },
            { id: 3, label: "COMP 300",
                font: {
                    color: highlightText,
                },
                color: {
                    background: highlightBackground,
                    highlight: {
                        background: highlightBackground,
                    },
                    hover: {
                        background: highlightBackground,
                    }
                }
            },
            { id: 4, label: "COMP 400" },
            { id: 5, label: "COMP 500" },
        ]);
        const edges = new vis.DataSet([
            { from: 1, to: 2 },
            { from: 2, to: 3 },
            { from: 3, to: 4 },
            { from: 3, to: 5 },
        ]);
        const container = this.fragment.getElementById("myChart");
        const data = { nodes, edges };
        const normalBackground = '#ffffe0';
        const normalText = '#008000';
        const options = {
            edges: {
                arrows: {
                    to: true,
                    middle: true,
                }
            },
            nodes: {
                font: {
                    size: 16,
                    color: normalText,
                },
                color: {
                    background: normalBackground,
                    border: normalText,
                    highlight: {
                        background: normalBackground,
                        border: normalText,
                    },
                    hover: {
                        background: normalBackground,
                        border: normalText,
                    }
                },
                shape: 'box'
            },
        };
        const network = new vis.Network(container, data, {});
        network.setOptions(options);
        container.querySelector('canvas').style['background'] = '#ffff69';
        return this;
    }
}
export default new ChartRenderer();
